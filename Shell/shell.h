#if !defined(MANDATORY_ASSIGNMENT_SHELL_H)
#define MANDATORY_ASSIGNMENT_SHELL_H

/**
 * Runs the shell loop until it gets cancelled.
 */
void shell_loop();

/**
 * @brief Read input from the command line and returns it
 */
char* shell_read();

/**
 * Parses the specified command.
 * @param userCommand a string containing a command
 * @return an array of arguments for the programs to be executed
 */
char*** shell_parse(char* userCommand);

/**
 * Executes a number of programs or inbuilt functions piping them together.
 * @param numberOfArgs the number of different arguments, i.e. the number of programs to run
 * @param argss an array of the arguments for the programs.
 */
void shell_execute(int numberOfArgs, char*** argss);




#endif // MANDATORY_ASSIGNMENT_SHELL_H
