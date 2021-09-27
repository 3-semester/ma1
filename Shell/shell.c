#include "shell.h"
#include "../String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 

int current_status = 1;

void shell_loop(){
	/*
	 * Keep taking commands until the program is exited.
	 */	
	while(current_status){
		char* string = shell_read();
		char** args = shell_parse(string);
        shell_execute(args);
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
			fprintf(stderr, "No command found called %s - ERRNO: %d - Status: %d", args[0], errno, current_status);
		}
		//exit(0);
	}
}
