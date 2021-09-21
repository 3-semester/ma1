#include "shell.h"
#include "../String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#include <stdio.h>

int current_status = 1;

void shell_loop(){
	char* str;
	
	while(current_status){

		shell_read(str);
        shell_execute(shell_parse(str));
	}

}

void shell_read(char* args){
	printf("Reading string");
    args = readLineFromStdin();
}

char** shell_parse(char* string){
	printf("Parsing string");
	return splitString(string, NULL);
}

void shell_execute(char** args){
	
	pid_t pid;

	pid = fork();
	printf("%d", pid);
	if(pid != 0){
		waitpid(pid, &current_status, 0);
	}else{
		printf("Executing:  ");
		execve(args[0], args, 0);
	}
}
