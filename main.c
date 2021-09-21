#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdbool.h>
// waitpid()
#include <sys/wait.h>
#include "Shell/shell.h"

int main(){
	// spin up the shell
	shell_loop();
	return 0;
}




