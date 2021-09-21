#include "shell.h"
#include "../String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int current_status = 1;

void shell_loop(){
	char* str;
	
	while(current_status){

		shell_read(&str);
        shell_execute(shell_parse(str));
	}

}

void shell_read(char** args){
    args = trim(readLineFromStdin());
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
		

		if(execve(args[0], args, 0) == -1){
			printf("Failed to execute");
		}
		exit(0);
	}
}
