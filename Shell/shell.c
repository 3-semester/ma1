#include "shell.h"
#include "../String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <stdbool.h>
#include <fcntl.h>

/**
 * Creates a specified number of pipes and returns them back to back in an int array.
 * @param numPipes the number of pipes to create
 * @return an array of pipes
 */
int* createPipes(int numPipes);

/**
 * Connects up the correct pipes in the specified array of pipes to stdin and stdout of this process
 * @param pipes an array of pipes
 * @param numberOfPipes the length of the pipes array
 * @param processNumber the 0-indexed position of this process in the sequence of piped processed
 */
void connectPipes(int* pipes, int numberOfPipes, int processNumber);

/**
 * Redirects the input or output stream of this process.
 * @param totalNumberOfProcesses the total number of processes
 * @param processNumber 0th-indexed number of the process
 * @param processArgs the arguments to the process
 */
void redirectIO(int totalNumberOfProcesses, int processNumber, char** processArgs);

int current_status = 1;

void shell_loop(){
	/*
	 * Keep taking commands until the program is exited.
	 */
	while(true){
		printf("Shell: ");

		char* userCommand = shell_read();
		char*** argss = shell_parse(userCommand);
		int numberOfArgs = 0;
		while (argss[numberOfArgs]) numberOfArgs++;
		shell_execute(numberOfArgs, argss);

		for (int i = 0; argss[i] != NULL; ++i) {
			freeStringArray(argss[i]);
		}
		free(argss);
	}
}

char* shell_read(){
	return trim(readLineFromStdin());
}

char*** shell_parse(char* userCommand){
	char*** argss = calloc(500, sizeof(char**));

	char** commands = splitString(userCommand, pipeString);


	//Todo: check for redirection
	int numberOfCommands = 0;
	while (commands[numberOfCommands] != NULL) {
		argss[numberOfCommands] = splitString(trim(commands[numberOfCommands]), NULL);
		numberOfCommands++;
	}
	realloc(argss, (numberOfCommands + 1) * sizeof(char**));
	return argss;
}

void shell_execute(int numberOfArgs, char*** argss){
	pid_t pid;
	int* pipes = createPipes(numberOfArgs - 1);
	for (int i = 0; i < numberOfArgs; ++i) {
		pid = fork();

		if (pid == 0){ //In child
			connectPipes(pipes, numberOfArgs - 1, i);
			redirectIO(numberOfArgs, i, argss[i]);
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
	int *pipes = calloc(numPipes, sizeof(int)*2);
	for (int i = 0; i < numPipes; i++) {
		pipe((pipes+(i*2)));
	}
	return pipes;
}

void connectPipes(int* pipes, int numberOfPipes, int processNumber){
	if (pipes == NULL || processNumber > numberOfPipes) return;
	if (processNumber != 0) dup2(*(pipes + 2 * (processNumber - 1)), STDIN_FILENO); //Set stdin to read from pipe
	if (processNumber < numberOfPipes) dup2(*(pipes + (processNumber * 2) + 1), STDOUT_FILENO); //Set stdout to write to pipe
}

void redirectIO(int totalNumberOfProcesses, int processNumber, char** processArgs){
	if (processNumber != 0 && processNumber != totalNumberOfProcesses-1) return;
	int openFlag, stream;
	if (processNumber == 0){
		openFlag = O_RDONLY; stream = STDIN_FILENO;
		while (*(++processArgs) && !strcmp(*(processArgs), redirectInputString));
	} else {
		openFlag = O_WRONLY; stream = STDOUT_FILENO;
		while (*(++processArgs) && !strcmp(*(processArgs), redirectOutputString));
	}
	if (!(*processArgs)) return;
	int fd = open(trim(*(++processArgs)), openFlag);
	dup2(fd, stream);
	close(fd);
}