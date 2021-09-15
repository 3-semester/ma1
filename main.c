
<<<<<<< HEAD
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

=======
>>>>>>> 98e0a781bb3ffc83790489784f0e9aaacc77b0b8
