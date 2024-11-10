/*************************************************************************/
/* File Name : program3.c                                                */
/* Purpose   : This C-file reads command-line arguments, parses integers */
/*             and strings, and outputs them as specified.               */
/*                                                                       */
/* Author(s) : assistant                                                 */
/*************************************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    int intArray[10];       // Array to store integer arguments
    int intCount = 0;       // Counter to keep track of the number of integers
    char combinedString[250] = ""; // String to store combined non-integer arguments
    int temp;               // Temporary variable for integer conversion

    // Loop through each argument (skip argv[0], which is the program name)
    for (int i = 1; i < argc; i++) {
        // Check if the argument is an integer using sscanf
        if (sscanf(argv[i], "%d", &temp) == 1) {
            // If sscanf finds an integer, store it in intArray
            intArray[intCount++] = temp;
        } else {
            // For non-integer arguments, append to combinedString
            if (i == 1 && strncmp(argv[i], "./", 2) == 0) {
                // Remove "./" from the first argument if present
                strcat(combinedString, argv[i] + 2);
            } else {
                // Append argument to combinedString as-is
                strcat(combinedString, argv[i]);
            }
            // Add a space after each argument except the last one
            if (i < argc - 1) {
                strcat(combinedString, " ");
            }
        }
    }

    // Print each integer stored in intArray, each on a new line
    for (int i = 0; i < intCount; i++) {
        printf("%d\n", intArray[i]);
    }

    // Print the combined string of non-integer arguments
    printf("%s\n", combinedString);

    return 0;
}
