
#define TRUE 1

int main(){

	while(TRUE){
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

