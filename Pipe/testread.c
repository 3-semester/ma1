#include <stdlib.h> 
#include <stdio.h> 
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>

int main(){
    char received[30]; 
    scanf("%s",received);
    printf("i received this: %s\n",received);
    return 0;
}