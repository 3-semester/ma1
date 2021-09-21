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

/**
 * Creates a new string the same length as the specified string and containing a copy of
 * the its text.
 * @param string the string to copy
 * @return a new string containing the supplied text
 */
char* newStringFromString(char* string);

/**
 * Reads a line from stdin and returns a new string with the read contents
 * @return a new string with the contents of the next line in stdin
 */
char* readLineFromStdin();

/**
 * Trims trailing and leading whitespace from specified string and resizes it.
 * @param string the string to trim
 * @return the passed pointer
 */
char* trim(char* string);

/**
 * Splits a string at every occurrence of the specified delimiter and returns each new substring.
 * @param string the string to split
 * @param delim the delimiter between each substring
 * @return a new array of strings containing the found substrings
 */
char** splitString(char* string, char* delim);

#endif //MANDATORY_ASSIGNMENT_SHELL_STRING_H
