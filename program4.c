/*************************************************************************/
/* File Name : program4.c                                                */
/* Purpose   : This C-file reads command-line arguments, parses integers */
/*             and strings, and outputs them as specified.               */
/*                                                                       */
/* Author(s) : assistant                                                 */
/*************************************************************************/

#include <stdio.h>
#include "my_string.h"

int main() {
    char str[] = "Hello,this,is,a,test,string";
    const char delim[] = ",";

    printf("Testing my_strtok with string: \"%s\" and delimiter \"%s\"\n", str, delim);

    // Get the first token
    char *token = my_strtok(str, delim);
    
    // Continue to get tokens until NULL is returned
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = my_strtok(NULL, delim);  // Pass NULL to continue from the last position
    }

    return 0;
}
