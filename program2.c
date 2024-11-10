/*************************************************************************/
/* File Name : program2.c                                                */
/* Purpose   : This C-file tests the new functions in the "my_string"    */
/*             library (my_strrev and my_strccase).                      */
/*                                                                       */
/* Author(s) : Danny Lin                                                 */
/*************************************************************************/

#include <stdio.h>
#include "my_string.h"

int main() {
    // Define sample strings for testing
    char my_string1[] = "Hello World!";
    char my_string2[] = "Hello World!";

    // Display the original string, then reverse it with my_strrev
    printf("Original string for reversal: \"%s\"\n", my_string1);
    printf("Reversed string: \"%s\"\n", my_strrev(my_string1));

    // Display the original string, then change its case with my_strccase
    printf("Original string for case change: \"%s\"\n", my_string2);
    printf("Case-changed string: \"%s\"\n", my_strccase(my_string2));

    return 0;
}
