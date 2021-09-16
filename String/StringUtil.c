//
// Created by Nylander on 16-09-2021.
//

#include "StringUtil.h"
#include <stdlib.h>



char* newString(unsigned long long length){
	if (length > MAX_STRING_LENGTH) return NULL;

	char* string = NULL;
	while (string == NULL) string = calloc(length + 1, sizeof(char));
	return string;
}