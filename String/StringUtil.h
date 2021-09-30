//
// Created by Nylander on 16-09-2021.
//

#ifndef MANDATORY_ASSIGNMENT_SHELL_STRING_H
#define MANDATORY_ASSIGNMENT_SHELL_STRING_H

/**
 * The maximal length of a string in characters
 */
#include <stdbool.h>

#define MAX_STRING_LENGTH 32768
const char pipeString[] = "|";
/**
 * Respectively the redirect input and output characters
 */
const char redirectIOCharacters[] = {'<', '>'};
const char redirectOutputString[] = ">";
const char redirectOutputAppendString[] = ">>";
const char redirectInputString[] = "<";
const char redirectInputAppendString[] = "<<";



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
 * @param delim the delimiter between each substring, if NULL a single space is used
 * @return a new array of strings containing the found substrings and NULL as the final element
 */
char** splitString(char* string, char* delim);

/**
 * Frees all the memory used by an array of strings, including the strings, where the final element is NULL.
 * @param stringArray the array to free
 */
void freeStringArray(char** stringArray);

/**
 * Returns the position of the of last occurrence of the specified needle in the specified haystack
 * @param haystack the string in which to find the position of the needle
 * @param needle the string to find the position of the last occurrence of in the haystack
 * @return the position of the last occurrence of needle in the haystack or -1 if not contained in the haystack
 */
int getLastOccurrenceOfString(char* haystack, char* needle);

/**
 * Returns the position of the of last occurrence of the specified needle in the specified haystack
 * @param haystack the string in which to find the position of the needle
 * @param needle the character to find the position of the last occurrence of in the haystack
 * @return the position of the last occurrence of needle in the haystack or -1 if not contained in the haystack
 */
int getLastOccurrenceOfCharacter(char* haystack, char needle);

/**
 * Returns whether the specified null-terminated string contains the specified character
 * @param string the null-terminated string to search
 * @param character the character to find
 * @return true if the character is contained in the string, otherwise false
 */
bool stringContainsCharacter(char* string, char character);

/**
 * Returns whether the specified null-terminated string contains any of the specified characters
 * @param string the null-terminated string to search
 * @param characters an array of characters to find an element of
 * @return true if any of the characters is contained in the string, otherwise false
 */
bool stringContainsCharacters(char* string, char characters[]);

#endif //MANDATORY_ASSIGNMENT_SHELL_STRING_H
