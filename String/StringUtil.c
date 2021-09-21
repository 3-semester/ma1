//
// Created by Nylander on 16-09-2021.
//

#include "StringUtil.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


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