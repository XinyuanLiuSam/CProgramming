
/**
 * Practical 7 (week 9) - (C ) Arrays and Iteration - GS
 *
 * Question 4 - Handling more realistic names
 *
 * @file to_uppercase2.c
 * @brief Converts names with lowercase/uppercase letters and commas to
 * uppercase.
 *
 * This C program performs the following operations:
 * - Repeatedly prompts user to enter a string of no more than 20 characters.
 * - Each string contains only letters (a-z or A-Z) and commas (to separate
 * names).
 * - Converts all lowercase letters to uppercase while leaving commas and
 * uppercase letters unchanged.
 *
 * - Terminates the program when the user inputs 'q' or 'Q'.
 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   2025-05-14
 * @copyright   :   Copyright (c) 2025
 */

// #include <ctype.h>   // For islower(), toupper()
#include <stdio.h>   // For printf(), scanf()
#include <stdlib.h>  // For general purpose functions (not used here)
#include <string.h>  // For strcmp(), strlen()

int main(void) {
  char input[21];   ///< Buffer to store user input (max 20 characters + '\0')
  char output[21];  ///< Buffer to store converted output string

  while (1) {
    printf("Enter a person's name (q or Q to quit):");

    // Read the input as string up to 20 characters from user
    if (scanf("%20s", input) != 1) {  // Limit input to 20 chars
      printf("Input error. Please try again.\n");
      continue;
    }

    // Exit condition if enter 'q' or 'Q'
    if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
      printf("Exiting program.\n");
      return 0;
    }

    // Validate input: allow lowercase/uppercase letters and commas
    int valid = 1;
    for (int i = 0; input[i] != '\0'; ++i) {
      char ch = input[i];
      if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
            ch == ',')) {
        valid = 0;
        break;
      }
    }

    if (!valid) {
      printf("Invalid input. Use lowercase/uppercase letters and commas.\n");
      continue;
    }

    // commas Convert to uppercase
    for (int i = 0; input[i] != '\0'; ++i) {
      if (input[i] >= 'a' && input[i] <= 'z') {
        output[i] = input[i] - 32;  // ASCII lowercase to uppercase
      } else {
        output[i] = input[i];  //
      }
    }
    output[strlen(input)] = '\0';  // Null-terminate the output string

    // print input and output
    printf("input \t\t\t  output\n");
    printf("%-20s \t %-20s\n", input, output);
  }

  return 0;  // Exit program normally
}