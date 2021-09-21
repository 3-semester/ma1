#if !defined(MANDATORY_ASSIGNMENT_SHELL_H)
#define MANDATORY_ASSIGNMENT_SHELL_H



/**
 * @brief Start the shell loop
 *  Runs the shell loop until it gets cancelled.
 */
void shell_loop();


/**
 * @brief Read input from the command line and returns it
 */
char* shell_read();

/**
 * @brief Parse the arguments 
 * 
 * @param string 
 */
char** shell_parse(char* string);


/**
 * @brief Execute the right program or inbuilt functions
 * 
 * @param args 
 */
void shell_execute(char** args);




#endif // MANDATORY_ASSIGNMENT_SHELL_H
