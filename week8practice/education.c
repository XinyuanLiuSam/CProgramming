/**
 * @Practical 6 (week 8)
 *
 * Question 5 - Calculating educational attainment
 *
 * @file        education.c
 * @brief
 *               Allows quitting with 'q'.
 *
 * This C program:
 * - reads in a positive integer representing the number of years
 * a person has spent in education so far and
 *  prints out the level of educational attainment
 * associated with that number of year's education. Use the following guide:

    0-7 years inclusive - Primary level education
    8-12 years inclusive - Secondary level education
    13+ years   - Tertiary level education.
 * - Allows the user to quit by entering 'q'.
 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   10/05/2025
 * @copyright   :   Copyright (c) 2025
 */
#include <stdio.h>   // For printf(), scanf()
#include <stdlib.h>  // For atoi()
#include <string.h>  // For strcpy()
int main(void) {
  char input[20];  // buffer to hold user input (string)
  int years;
  char level_desc[50];
  // Input validation: keep prompting until a valid number of year's education
  // is entered
  while (1) {
    printf(
        "Please enter a valid number[1-20] of year's education  (or 'q' to quit): ");
    scanf("%s", input);  // read input as string

    // Check if user wants to quit
    if (strcmp(input, "q") == 0) {
      printf("Exiting program.\n");
      exit(0);  // exit the program
    }

    // Convert input to integer
    years = atoi(input);

    // Determine education level
    if (years >= 1 && years <= 7) {
      strcpy(level_desc, "Primary level education.");
    } else if (years > 7 && years <= 13) {
      strcpy(level_desc, "Secondary level education.");
    } else if (years > 13 && years <= 20) {
      strcpy(level_desc, "Tertiary level education.");
    } else {
      printf("Invalid input. Please try again.\n");
      continue;
    }

    // Output result
    printf("Educational attainment: %s\n", level_desc);
  }
  return 0;
}