

//executest to processes given two seperate argument lists and pipes them together
void executeTwoProcesses(char** argset1, char** argset2);


//tokenizes a sting
char** getArgumentsFromString(char* string);



//checks whether a string contains a '|' symbol
bool doesStringContainPipe(char* string);




//splits a given string in half and return an pointer pointer to them
char** splitStringInHalf(char* string);

void shelldoubleparse(char* String, char*** argSt1, char*** argSt2);