
/**
 * Practical 7 (week 9) - (C ) Arrays and Iteration - GS
 *
 * Question 3 - Lowercase  to uppercase
 *
 * @file process_ages.c
 * @brief This program reads a batch of age inputs, calculates and displays
 *        the maximum, minimum, and average for each batch.
 *
 * This C program performs the following operations:
 * - Repeatedly reads from the user, a string of no more than 20 characters.
 * - the string represents a person's name, consists only of lower case letters
 * and commas (the commas are to separate names).
 * - convert the string to all uppercase letters and print it
 * - followed by a newline as shown below.
 * - Comma characters should be left unchanged.
 * - Allows complete exit of the program by entering `q` or `Q`
 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   2025-05-14
 * @copyright   :   Copyright (c) 2025
 */

#include <ctype.h>
#include <stdio.h>   // For printf(), scanf()
#include <stdlib.h>  // For atoi()
#include <string.h>  // For strcpy()

int main(void) {
  char input[21];  // String input buffer to handle names or command
  char output[21];
  while (1) {
    printf("Enter a person's name (q or Q to quit):");
    // Read the input as string from user
    if (scanf("%21s", input) != 1) {  // Limit input to 20 chars
      printf("Input error. Please try again.\n");
      continue;
    }

    // Exit if enter 'q' or 'Q'
    if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
      printf("Exiting program.\n");
      return 0;
    }

    // Validate input: only lowercase letters and commas allowed
    int valid = 1;
    for (int i = 0; input[i] != '\0'; ++i) {
      if (!(input[i] >= 'a' && input[i] <= 'z') && input[i] != ',') {
        valid = 0;
        break;
      }
    }

    if (!valid) {
      printf("Invalid input. Use only lowercase letters and commas.\n");
      continue;
    }

    // commas Convert to uppercase
    for (int i = 0; input[i] != '\0'; ++i) {
      if (input[i] >= 'a' && input[i] <= 'z') {
        output[i] = input[i] - 32;
      } else {
        output[i] = input[i];  //
      }
    }
    output[strlen(input)] = '\0';  // End output string

    // print input and output
    printf("%-20s \t %-20s\n", input, output);
  }

  return 0;  // Exit program normally
}