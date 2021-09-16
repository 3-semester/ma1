//
// Created by Nylander on 16-09-2021.
//

#include "StringUtil.h"
#include <stdlib.h>
#include <string.h>



char* newString(unsigned long long length){
	if (length > MAX_STRING_LENGTH) return NULL;

	char* string = NULL;
	while (string == NULL) string = calloc(length + 1, sizeof(char));
	return string;
}

char* newStringFromString(char* string){
	if(string == NULL) return newString(0);
	char* newString = newString(strlen(string));
	strcpy(newString, string);
	return newString;
}