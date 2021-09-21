#include "shell.h"
#include "../String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>

int current_status = 1;

void shell_loop(){
	char** str;
	
	while(current_status){
		shell_read(str);
        shell_execute(shell_parse(str));
	}

}

void shell_read(char** args){
    *args = readLineFromStdin();
}

char** shell_parse(char** args){
return splitString(args, NULL);
}

void shell_execute(char** args){

	pid_t pid;

	pid = fork();

	if(pid != 0){
		waitpid(pid, -1, current_status);
	}else{
		execvp(args[0], args);
	}
}
