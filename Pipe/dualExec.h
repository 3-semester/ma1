#include <stdbool.h>

//executest to processes given two seperate argument lists and pipes them together
void executeTwoProcesses(char** argset1, char** argset2);


//tokenizes a sting
char** getArgumentsFromString(char* string);

void shelldoubleparse(char* String, char*** argSt1, char*** argSt2);