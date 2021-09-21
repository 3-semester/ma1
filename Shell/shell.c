#include "String/StringUtil.h";

void shell_loop(void){
	char** str;
	int current_status;

	while(current_status){
		shell_read(str);
        shell_execute(shell_parse(str));
	}

    return 1;
}

void shell_read(char** args){
    args = readLineFromStdin();
}

char** shell_parse(char** args){
}

void shell_execute(char** args){

}
