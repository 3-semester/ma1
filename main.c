#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include "Shell/shell.h"


/**
 *	This is the first thing that runs when this program is started
 */
int main(){
	// spin up the shell
	shell_loop_ProposedAlternative();
	return 0;
}




