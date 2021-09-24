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
    int pid2;

    if(pid1 != 0) {//enter parent

        pid2 = fork();//create second child

        if(pid2 == 0){//second child run process

            //connect read end to stdin
            dup2(fd[0], STDIN_FILENO);
            execvp(argset2[0], argset2);
        }

        wait(NULL);

    }else{ //first child run process
        //connect write end to stdout
        dup2(fd[1], STDOUT_FILENO);
        execvp(argset1[0], argset1);

    }
    
}

char** getArgumentsFromString(char* string){
    return splitString(string, NULL);
}
int doesStringContainPipe(char* string){
    if (strchr(string, '|')!= NULL) {//true
        return 1;
    }else{//false
        return 0;
    }

}
char** splitStringInHalf(char* string){
    //strcpy(string, string);
    //printf("in func\n");
    char** stringHalves = (char**)malloc(2*sizeof(char*));
    //printf("after malloc\n");
    *(stringHalves) = strtok(string, "|");
    //printf("after strtok1\n");
    *(stringHalves+1) = strtok(NULL, "|");
    //printf("after strtok2\n");
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

/*
//simple test in main
int main(void){

//arrays to test whether it can pipe programs
    
    //char* test = "./testprint | ./testread";

    //char** retval = splitStringInHalf(newStringFromString(test));
    //char* t1 = *(retval);
    //char* t2 = *(retval+1);
    //t1 = newStringFromString(t1);
    //t2 = newStringFromString(t2); 
    //TODO for some reason last letter in func get duplicated if it has space in front of it

    //char** arg1 = splitString(t1, " ");
    //char** arg2 = splitString(t2, " ");
    //strtok removes delimiters at beginning and end, no need to trim

    //does string contain pipe?
    //printf("string contains pipe: %d\n", (int)doesStringContainPipe(test))
    

    char* test2 = "./testprint | ./testread";
    char** arg1;
    char** arg2;

    shelldoubleparse(test2, &arg1, &arg1);



    printf("arg sets: #%s#%s# and #%s#%s#\n", arg1[0], arg1[1], arg2[0], arg2[1]);

    executeTwoProcesses(arg1, arg2);




    //char* arg1[] = {"./testprint", NULL};
    //char* arg2[] = {"./testread", NULL};

    //executeTwoProcesses(arg1, arg2);
  
    return 0;
}
*/


