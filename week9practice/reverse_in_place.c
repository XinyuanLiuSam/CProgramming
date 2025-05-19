
/**
 * Practical 7 (week 9) - (C ) Arrays and Iteration - GS
 *
 * Question 5 - Reversing a string
 *
 * @file reverse_in_place.c
 * @brief Reads in a string (20 characters or less) from the user into an array,
 * then reverses that string and prints out the reversed version followed by a
 * newline.
 *
 * This C program performs the following operations:
 * - Reads in a string (20 characters or less) from the user
 * - Reverses that string and prints out the reversed version followed by a
 * newline
 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   2025-05-14
 * @copyright   :   Copyright (c) 2025
 */
#include <stdio.h>   // For printf(), scanf()
#include <stdlib.h>  // For exit()
#include <string.h>  // For strlen(), strcmp()

#define MAX_LEN 20

/// @brief 
/// @param  
/// @return 
int main(void) {
  char input[MAX_LEN + 1];   // +1 for null-terminator
  char output[MAX_LEN + 1];  // store reversed string

  while (1) {
    printf("Enter a string (q or Q to quit):");

    // Read user input string (limit to MAX_LEN chars)
    if (scanf("%20s", input) != 1) {
      printf("Input error. Please try again.\n");
      continue;
    }

    // Exit if enter 'q' or 'Q'
    if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
      printf("Exiting program.\n");
      return 0;
    }

    // Compute length of the input string
    int len = strlen(input);
    // Reverse the string into the output array
    for (int i = 0; i < len; ++i) {
      output[i] = input[len - 1 - i];  // reverse copy for each char
    }

    // terminate the reversed string with null character
    output[len] = '\0';

    // Print the original and reversed string
    printf("input \t\t\t  output\n");
    printf("%-20s \t  %-20s\n", input, output);
  }
  return 0;
}