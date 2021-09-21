#if !defined(MANDATORY_ASSIGNMENT_SHELL_H)
#define MANDATORY_ASSIGNMENT_SHELL_H



/**
 * @brief Start the shell loop
 *  Runs the shell loop until it gets cancelled.
 */
void shell_loop();


/**
 * @brief Read input from the command line and save it in args
 * 
 * @param args the variable to save arguments in
 */
void shell_read(char** args);

/**
 * @brief Parse the arguments 
 * 
 * @param args 
 */
char** shell_parse(char** args);


/**
 * @brief Execute the right program or inbuilt functions
 * 
 * @param args 
 */
void shell_execute(char** args);




#endif // MANDATORY_ASSIGNMENT_SHELL_H
