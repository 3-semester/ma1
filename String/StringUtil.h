//
// Created by Nylander on 16-09-2021.
//

#ifndef MANDATORY_ASSIGNMENT_SHELL_STRING_H
#define MANDATORY_ASSIGNMENT_SHELL_STRING_H

/**
 * The maximal length of a string in characters
 */
#define MAX_STRING_LENGTH 32768

/**
 * Allocated a new string and returns it or NULL if length is greater than MAX_STRING_LENGTH
 * @param length the length of the string in characters
 * @return a newly allocated char* or NULL
 */
char* newString(unsigned long long length);

#endif //MANDATORY_ASSIGNMENT_SHELL_STRING_H
