#include "shell.h"
#include "../String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <stdbool.h>
#include "../Pipe/dualExec.h"
#include <string.h>

/**
 * Creates a specified number of pipes and returns them back to back in an int array.
 * @param numPipes the number of pipes to create
 * @return an array of pipes
 */
int* createPipes(int numPipes);

int current_status = 1;

void shell_loop(){
	/*
	 * Keep taking commands until the program is exited.
	 */
	char* userCommand = NULL;
	while(current_status){
		printf("Shell: ");
		if (userCommand != NULL) free(userCommand);
		userCommand = shell_read();

		//check if userCommand contains pipe
		if (!stringContainsCharacter(userCommand, '|')) {//if it doesnt contain pipe run single program
			char **args = shell_parse(userCommand);
			shell_execute(args);
			freeStringArray(args);
			continue;
		}
		//split up into two strings
		char **argset1;
		char **argset2;
		shelldoubleparse(userCommand, &argset1, &argset2);

		//print so you can see args
		printf("\narg sets: #%s#%s# and #%s#%s#\n", argset1[0], argset1[1], argset2[0], argset2[1]);
		fflush(stdout);

		//execute
		executeTwoProcesses(argset1, argset2);
		freeStringArray(argset1);
		freeStringArray(argset2);
	}
}

char* shell_read(){
	return trim(readLineFromStdin());
}

char** shell_parse(char* string){
	return splitString(string, NULL);
}

char*** shell_parse_ProposedAlternative(char* userCommand){
	char*** argss = calloc(500, sizeof(char**));

	char** commands = (char***) splitString(userCommand, "|");
	int numberOfCommands = 0;
	while (commands[numberOfCommands] != NULL) {
		argss[numberOfCommands] = splitString(trim(commands[numberOfCommands]), NULL);
		numberOfCommands++;
	}
	recalloc(argss, numberOfCommands, sizeof(char**));
	return argss;
}

void shell_execute(char** args){
	pid_t pid = fork();
	if(pid != 0){
		waitpid(pid, &current_status, 0);
		return;
	}
	//In child process from here on
	if(execvp(args[0], args) == -1){
		fprintf(stderr, "No command found called %s - ERRNO: %d", args[0], errno);
	}
	exit(0);
}

void shell_execute_ProposedAlternative(int numberOfArgs, char*** argss){
	pid_t pid;
	int* pipes = createPipes(numberOfArgs - 1);
	for (int i = 0; i < numberOfArgs; ++i) {
		pid = fork();

		if (pid == 0){ //In child
			if (i != 0) dup2(*(pipes + 2 * (i - 1)), STDIN_FILENO); //Set stdin to read from pipe
			if (i < numberOfArgs - 1) dup2(*(pipes + (i * 2) + 1), STDOUT_FILENO); //Set stdout to write to pipe
			if(execvp(argss[i][0], argss[i]) == -1){
				fprintf(stderr, "No command found called %s - ERRNO: %d", argss[i][0], errno);
				exit(0);
			}
		}
	}
	waitpid(pid, &current_status, 0); //Wait for the last process created to finish
}

int* createPipes(int numPipes){
	if (numPipes == 0) return NULL;
	int pipes = calloc(numPipes, sizeof(int)*2);
	for (int i = 0; i < numPipes; i += 2) {
		pipe((pipes+i));
	}
	return pipes;
}