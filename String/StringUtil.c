//
// Created by Nylander on 16-09-2021.
//

#include "StringUtil.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


char* newString(unsigned long long length){
	if (length > MAX_STRING_LENGTH) return NULL;

	char* string = NULL;
	while (string == NULL) string = calloc(length + 1, sizeof(char));
	return string;
}

char* newStringFromString(char* string){
	if(string == NULL) return newString(0);
	char *newStr = newString(strlen(string));
	strcpy(newStr, string);
	return newStr;
}

char readStringBuffer[MAX_STRING_LENGTH];
char* readLineFromStdin(){
	fgets(readStringBuffer, sizeof(readStringBuffer), stdin);
	return newStringFromString(readStringBuffer);
}

char* trim(char* string){
	if(string == NULL) return string;
	size_t length = strlen(string), startLength = length;
	//remove trailing
	while(isspace(string[length-1])) string[--length] = 0;
	//remove leading
	char *newStart = string;
	while(newStart && isspace(*newStart)) newStart++, length--;
	//Move string back to given pointer
	if (newStart != string) memmove(string, newStart, length+1);
	//Return any now unused memory to the OS
	if (length != startLength) realloc(string, (length+1) * sizeof(char));
	//Done :)
	return string;
}

char** splitString(char* string, char* delim){
	if (string == NULL) return NULL;
	if (delim == NULL) delim = " ";
	char** strings = malloc(500 * sizeof(char*));

	*strings = strtok(string, delim);
	int i = 0;
	while (*(strings+i) != NULL){
		*(strings + ++i) = strtok(NULL, delim);
	}
	realloc(strings, sizeof(char*) * (i+1));
	return strings;
}

void freeStringArray(char** stringArray){
	char** strArr = stringArray;
	while (stringArray){
		free(*stringArray);
		stringArray++;
	}
	free(strArr);
}

bool stringContainsCharacter(char* string, char character){
	return strchr(string, character) != NULL;
}