//
// Created by Nylander on 16-09-2021.
//

#include "StringUtil.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static int const initialStringSize = 10;

struct _string {
	char* text;
	//Allocated size in number of characters
	int textSize;
};

/**
 * Resizes the text of the specified String and returns whether
 * the text now has the desired size.
 * @param newSize
 * @param string
 * @return
 */
bool resizeText(int newMaxLength, String string){
	if(realloc(string->text, sizeof(char) * newMaxLength) != NULL){
		string->textSize = newMaxLength;
		return true;
	}
	return false;
}

bool setTextSize(int newMaxLength, String string){
	if (newMaxLength == string->textSize || resizeText(newMaxLength, string)) return true;

	char* oldText = string->text;
	string->text = NULL;
	if (!resizeText(newMaxLength, string)){
		string->text = oldText;
		return false;
	}
	memcpy(string->text, oldText, sizeof(char) * string->textSize);
	free(oldText);
	return true;
}



String newString(){
	String string = NULL;
	while (string == NULL){
		string = malloc(sizeof(struct _string));
	}
	string->textSize = 0;

	setTextSize(initialStringSize, string);
}