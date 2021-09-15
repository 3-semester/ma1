#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdbool.h>




int main(){

	while(true){
	
	// read command from prompt
	//char inputStr[100];  
	//scanf("%s", inputStr);
        
	// read_command(command, parameters);
			
	int childPid = fork(); 
	
	if(childPid > 0)
	{
		printf("Error!");
		return 0;
	}

	if(childPid != 0)
	{
		//waitpid(-1, &status, 0);
		printf("I am a parent with PID: %d", getpid());
	} 
	
	else 
	{
		//execve(command, parameters, 0);
		printf("I am a child with PID: %d", getpid());
	}
	}
	return 0;
}
