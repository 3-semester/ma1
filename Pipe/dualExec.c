#include "../String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include "dualExec.h"
#include <string.h>


void executeTwoProcesses(char** argset1, char** argset2){
    //TODO get function that split args into two sets

    //make pipe
    int fd[2];
    pipe(fd);

    int pid1 = fork();//create first child

	if (pid1 == 0) { //first child run process
		//connect write end to stdout
		dup2(fd[1], STDOUT_FILENO);
		execvp(argset1[0], argset1);
	}

	//enter parent
	int pid2 = fork();//create second child
	if (pid2 == 0) {//second child run process
		//connect read end to stdin
		dup2(fd[0], STDIN_FILENO);
		execvp(argset2[0], argset2);
	}

	wait(NULL);
}

char** getArgumentsFromString(char* string){
    return splitString(string, NULL);
}

char** splitStringInHalf(char* string){
    char** stringHalves = (char**)malloc(2*sizeof(char*));
    *(stringHalves) = strtok(string, "|");
    *(stringHalves+1) = strtok(NULL, "|");
    return stringHalves;
}

//vi giver funktionen en string og addressen til to arrays
//hvilket er en pointer(*) til en pointer pointer(**)
//indholdet skrives tilbage i de pointer pointers
void shelldoubleparse(char* String, char*** argSt1, char*** argSt2){
    //split string into two strings
    char** retval = splitStringInHalf(newStringFromString(String));
    //printf("\nafter splitstring");
    fflush(stdout);

    //save into two new strings instead of array
    //allocate some memory for the strings

    char* t1 = malloc(100*sizeof(char));
    char* t2 = malloc(100*sizeof(char));
    strcpy(t1, *(retval));
    strcpy(t2, *(retval+1));


    //split into array and save to desired "array" location
    *argSt1 = splitString(t1, " ");
    *argSt2 = splitString(t2, " ");

    //deallocate strings
    //free(t1);
    //free(t2);
}



