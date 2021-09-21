#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdbool.h>

// waitpid()
#include <sys/wait.h>

int main(){
	
	// spin up the shell
	shell_loop();

	return 0;
}



void shell_loop(void){
	char** string;
	char** arguments;
	
	int current_status;

	while(current_status){
		// read arguments

		// parse arguments

		// execute
	}
}