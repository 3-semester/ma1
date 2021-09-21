#include "../String/StringUtil.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 

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
            execve(argset2[0], argset2, 0);
        }

        wait(NULL);

    }else{ //first child run process
        //connect write end to stdout
        dup2(fd[1], STDOUT_FILENO);
        execve(argset1[0], argset1, 0);

    }
    
}



int main(void){


    return 0;
}