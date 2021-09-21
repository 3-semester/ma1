#include "StringUtil.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char**  splitter(char string[]){
    
    char* stringArrayBuffer[50] = {NULL};

    int arrIndex = 0;
    //read in first token
    char* token = strtok(string, " ");
    //continously read in tokens 
    while(token != NULL){
        stringArrayBuffer[arrIndex] = token;
        printf("%s", stringArrayBuffer[arrIndex]);
        arrIndex++;
        char* token = strtok(string, " ");
    }

    //check actual length
    int k = 0;
    while(stringArrayBuffer[k] != NULL){
        k++;
    }
    int length = k;

    //read in from buffer into actual array to be returned
    char** stringArray =(char**) malloc(length*(sizeof(char*)));
    memcpy(stringArray, stringArrayBuffer, length);

    return stringArray;
}

int main(void){
    char string[] = "hello hello hello";
    char** stringArr = splitter(string);

    int j = 0;  
    while (j > 2)
    {
        printf("%s\n", stringArr[j] );
        j++;
    }
    




}