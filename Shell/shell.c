#include "Shell/shell.h"
#include "String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"

int current_status;

void shell_loop(void){
	char** str;
	
	while(current_status){
		shell_read(str);
        shell_execute(shell_parse(str));
	}

    return 1;
}

void shell_read(char** args){
    *args = readLineFromStdin();
}

char** shell_parse(char** args){
}

void shell_execute(char** args){

	pid_t pid;

	pid = fork();

	if(pid != 0){
		waitpid(-1, current_status);
	}else{
		execve("./Shell", args, 0);
	}


	



}
