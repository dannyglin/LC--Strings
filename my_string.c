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
    while (str[len] != '\0') {
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
char* my_strcpy(char *dest, const char *src) {
    int i = 0;
    while ((dest[i] = src[i]) != '\0') {
        i++;
    }
    return dest;
}

char* my_strcpy2(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++) != '\0') ;
    return dest;
}

// strchr functions
char* my_strchr(const char *str, int c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == (char)c) {
            return (char*)&str[i];
        }
    }
    return NULL;
}

char* my_strchr2(const char *str, int c) {
    while (*str != '\0') {
        if (*str == (char)c) {
            return (char*)str;
        }
        str++;
    }
    return NULL;
}

// strcat functions
char* my_strcat(char *dest, const char *src) {
    int i = 0, j = 0;
    while (dest[i] != '\0') {
        i++;
    }
    while ((dest[i++] = src[j++]) != '\0') ;
    return dest;
}

char* my_strcat2(char *dest, const char *src) {
    char *d = dest;
    while (*d) {
        d++;
    }
    while ((*d++ = *src++) != '\0') ;
    return dest;
}

// strcmp functions
int my_strcmp(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

int my_strcmp2(const char *str1, const char *str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

// my_strrev function: reverses the string in place
char* my_strrev(char *str) {
    int left = 0;
    int right = my_strlen(str) - 1;
    while (left < right) {
        char temp = str[left];
        str[left++] = str[right];
        str[right--] = temp;
    }
    return str;
}

// my_strccase function: changes the case of each letter in the string
char* my_strccase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 'a' - 'A';  // Convert to lowercase
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';  // Convert to uppercase
        }
    }
    return str;
}

// my_strtok function: tokenizes a string based on a delimiter
static char *last_position = NULL;

char* my_strtok(char *str, const char *delim) {
    if (str != NULL) {
        last_position = str;  // Initialize with the new string
    } else {
        str = last_position;  // Continue from last token
    }

    if (str == NULL) {
        return NULL;  // No more tokens
    }

    // Skip leading delimiters
    while (*str && strchr(delim, *str)) {
        str++;
    }

    if (*str == '\0') {
        last_position = NULL;  // End of string reached
        return NULL;
    }

    // Mark the beginning of the token
    char *token_start = str;

    // Find the next delimiter
    while (*str && !strchr(delim, *str)) {
        str++;
    }

    if (*str) {
        *str = '\0';  // Null-terminate the token
        last_position = str + 1;  // Save the next position
    } else {
        last_position = NULL;  // End of string
    }

    return token_start;
}
