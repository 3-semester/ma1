//
// Created by Nylander on 16-09-2021.
//

#ifndef MANDATORY_ASSIGNMENT_SHELL_STRING_H
#define MANDATORY_ASSIGNMENT_SHELL_STRING_H

typedef struct _string* String;

String newString();
String newStringInitialLength(int length);
String newStringInitialText(char[] initialText);
void destroyString();

#endif //MANDATORY_ASSIGNMENT_SHELL_STRING_H
