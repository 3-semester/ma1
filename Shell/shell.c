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

int current_status = 1;

void shell_loop(){
	/*
	 * Keep taking commands until the program is exited.
	 */	
	while(current_status){
		printf("Shell: ");
		char* string = shell_read();
		
		//check if string contains pipe
		if (!doesStringContainPipe(newStringFromString(string))) {//if it doesnt contain pipe run single program
			char **args = shell_parse(string);
			shell_execute(args);
			continue;
		} else {
			//split up into two strings
			char **argset1;
			char **argset2;
			shelldoubleparse(string, &argset1, &argset2);

			//print so you can see args
			printf("\narg sets: #%s#%s# and #%s#%s#\n", argset1[0], argset1[1], argset2[0], argset2[1]);
			fflush(stdout);

			//execute
			executeTwoProcesses(argset1, argset2);
		}

		//free(string);
		//freeStringArray(args);

	}

}

char* shell_read(){
	return trim(readLineFromStdin());
}

char** shell_parse(char* string){
	return splitString(string, NULL);
}

void shell_execute(char** args){
	
	pid_t pid;

	pid = fork();
	if(pid != 0){
		waitpid(pid, &current_status, 0);
	}else{
		if(execvp(args[0], args) == -1){
			fprintf(stderr, "No command found called %s - ERRNO: %d", args[0], errno);
		}
		exit(0);
	}
}
