#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(){
		
	while(true){
		type_prompt();
		read_command(command, parameters);

		if(fork() != 0){
		  /* Parent code */
			waitpid(-1, &status, 0);
		} else {
			/* Child code*/
			execve(command, parameters, 0);

		}
	}
return 0;
}
