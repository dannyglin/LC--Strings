/*************************************************************************/
/* File Name : program1.c 											     */
/* Purpose   : this C-file tests the functions of the "my_string" library*/
/*                                                                       */
/*                                                                       */
/* Author(s) : tjf & you 											     */
/*************************************************************************/

#include <stdio.h>
#include <string.h>
#include "my_string.h"

int main() {
    // Define a sample string to test
    char my_string[100] = "Tom";

    // Print the sample string
    printf("Sample string: \"%s\"\n", my_string);

    // Test and print the string length using standard strlen
    printf("String's length: strlen() = %lu\n", strlen(my_string));

    // Test and print the string length using my_strlen (array notation)
    printf("String's length: my_strlen() = %lu\n", my_strlen(my_string));

    // Test and print the string length using my_strlen2 (pointer notation)
    printf("String's length: my_strlen2() = %lu\n", my_strlen2(my_string));

    return 0;
}
