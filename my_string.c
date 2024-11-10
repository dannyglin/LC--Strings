/*************************************************************************/
/* File Name : my_string.c 											     */
/* Purpose   : this C-file defines the functions previously declared	 */
/*             in the my_string.h header file 						     */
/*																		 */
/* Author(s) : tjf & you 											     */
/*************************************************************************/

#include <stdio.h>    // for printf, if used in your functions
#include <string.h>   // for strchr and other string functions, if used
#include "my_string.h" // include your header file for function declarations

// strlen functions
size_t2 my_strlen  (const char *str) {
	size_t2 len = 0 ;
	while (str[len] != '\0') {  // count up to the first NULL
		len++ ; 
	}
	return (len) ;
}

size_t2 my_strlen2 (const char *str) {
	const char* s;
	for (s = str; *s; ++s) ;
	return (s - str);
}

// strcpy functions
char* my_strcpy(char* dest, const char* src) {
    int i = 0;
    // Copy each character including null terminator
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
    return dest;
}

// Pointer arithmetic version
char* my_strcpy2(char* dest, const char* src) {
    char* start = dest;
    while ((*dest++ = *src++) != '\0');
    return start;
}

// strchr functions
char* my_strchr(const char* str, int c) {
    int i;
    for (i = 0; i <= my_strlen(str); i++) {
        if (str[i] == c) {
            return (char*)(str + i);
        }
    }
    return NULL;
}

// Pointer arithmetic version
char* my_strchr2(const char* str, int c) {
    while (*str != '\0') {
        if (*str == c) {
            return (char*)str;
        }
        str++;

    }
    // Check for null terminator match
    if (c == '\0') {
        return (char*)str;
    }

    return NULL;  // Return NULL if character not found
}

// Array notation version
char* my_strcat(char* dest, const char* src) {
    int dest_len = my_strlen(dest);
    int i;
    // Check for empty source string
    if (src[0] == '\0') {
        return dest;
    }
    for (i = 0; src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';
    return dest;
}

// Pointer arithmetic version
char* my_strcat2(char* dest, const char* src) {
    char* start = dest;
    // Move to end of dest
    while (*dest) {
        dest++;
    }
    // Copy src
    while ((*dest++ = *src++) != '\0');
    
    return start;
}

// Array notation version
int my_strcmp(const char* str1, const char* str2) {
    int i = 0;
    // Compare characters until difference found or end reached
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
        i++;
    }
    // If we reach here, strings are equal up to the length of shorter string
    return (str1[i] - str2[i]);
}

// Pointer arithmetic version
int my_strcmp2(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

// Reverses a string in place and returns pointer to the string
char* my_strrev(char* str) {
    // Handle empty string case
    if (str[0] == '\0') {
        return str;
    }
    int i;
    int length = my_strlen2(str);
    char copy[length + 1]; // Setup copy destination for temporary use
    my_strcpy2(copy, str); // Copy into that location
    for (i = 0; i < length; i++) {
        str[i] = copy[length - 1 - i];
    }
    str[length] = '\0';  // Ensure null termination
    return str;
}

// Changes case of all letters in string and returns pointer to the string
char* my_strccase(char* str) {
    char* ptr = str;
    while (*ptr != '\0') {
        // If uppercase letter, convert to lowercase
        if (*ptr >= 'A' && *ptr <= 'Z') {
            *ptr = *ptr + ('a' - 'A');
        }
        // If lowercase letter, convert to uppercase
        else if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr = *ptr - ('a' - 'A');
        }
        // Non-letter characters are left unchanged
        ptr++;
    }
    return str;
}

// Static variable to maintain state between calls
static char* next_token = NULL;

char* my_strtok(char* str, const char* delim) {
    char* token_start;
    // If str is provided, start tokenizing from there
    // If str is NULL, continue from last position
    if (str != NULL) {
        next_token = str;
    }
    // Return NULL if we've reached the end
    if (next_token == NULL) {
        return NULL;
    }
    // Skip leading delimiters
    while (*next_token != '\0') {
        const char* d = delim;
        int is_delim = 0;
        
        // Check if current char is a delimiter
        while (*d != '\0') {
            if (*next_token == *d) {
                is_delim = 1;
                break;
            }
            d++;
        }
        if (!is_delim) {
            break;
        }
        next_token++;
    }
    // If we've reached end of string, return NULL
    if (*next_token == '\0') {
        next_token = NULL;
        return NULL;
    }

    // Mark start of token
    token_start = next_token;
    
    // Find the next delimiter
    while (*next_token != '\0') {
        const char* d = delim;
        int is_delim = 0;
        
        // Check if current char is a delimiter
        while (*d != '\0') {
            if (*next_token == *d) {
                is_delim = 1;
                break;
            }
            d++;
        }
        
        if (is_delim) {
            // Replace delimiter with null terminator
            *next_token = '\0';
            next_token++;
            return token_start;
        }
        next_token++;
    }
    
    // If we get here, we hit the end of the string
    next_token = NULL;
    return token_start;
}
