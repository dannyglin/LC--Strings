/*************************************************************************/
/* File Name : program3.c                                                */
/* Purpose   : This C-file reads command-line arguments, parses integers */
/*             and strings, and outputs them as specified.               */
/*                                                                       */
/* Author(s) : Danny Lin                                                 */
/*************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAX_ARGS 10
#define MAX_STR_LEN 250

int main(int argc, char** argv) {
    int integers[MAX_ARGS];     // Array to store integer arguments
    int int_count = 0;          // Counter to keep track of the number of integers
    char result_str[MAX_STR_LEN] = ""; // String to store combined non-integer arguments
    int num;                    // Temporary variable for integer conversion

    // Loop through each argument (skip argv[0], which is the program name)
    char *program_name = argv[0];
    if (strncmp(program_name, "./", 2) == 0) {
        program_name += 2;  // Skip "./" characters
    }
    strcpy(result_str, program_name);

    // Process remaining arguments
    for (int i = 1; i < argc; i++) {
        // Try to convert to integer
        if (sscanf(argv[i], "%d", &num) == 1) {
            // Store integer
            integers[int_count++] = num;
        } else {
            // Handle string
            strcat(result_str, " ");
            strcat(result_str, argv[i]);
        }
    }

    // Print each integer stored in intArray, each on a new line
    for (int i = 0; i < int_count; i++) {
        printf("%d\n", integers[i]);
    }

    // Print the combined string of non-integer arguments
    printf("%s\n", result_str);

    return 0;
} 