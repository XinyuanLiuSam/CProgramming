/**
 * @Practical 6 (week 8)
 *
 * Question 6 - Translating a months number to its name
 *
 * @file        months.c
 * @brief
 *               Allows quitting with 'q'.
 *
 * This C program:
 * - r reads an integer (between 1 and 12) 
 * and prints out a three-letter abbreviation 
 * for a month corresponding to that number. 

    
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
  int month;
  char month_desc[50];
  // Input validation: keep prompting until a valid number of month
  // is entered
  while (1) {
    printf(
        "Please enter a valid number[1-12] of month  (or 'q' to quit): ");
    scanf("%s", input);  // read input as string

    // Check if user wants to quit
    if (strcmp(input, "q") == 0) {
      printf("Exiting program.\n");
      exit(0);  // exit the program
    }

    // Convert input to integer
    month = atoi(input);

    // Determine month mapping
    if (month == 1) {
      strcpy(month_desc, "January");
    } else if (month == 2) {
      strcpy(month_desc, "Feburary");
    } else if (month == 3) {
      strcpy(month_desc, "March");
    } else if (month == 4) {
      strcpy(month_desc, "April");
    } else if (month == 5) {
      strcpy(month_desc, "May");
    } else if (month == 6) {
      strcpy(month_desc, "June");
    } else if (month == 7) {
      strcpy(month_desc, "July");
    } else if (month == 8) {
      strcpy(month_desc, "August");
    } else if (month == 9) {
      strcpy(month_desc, "September");
    } else if (month == 10) {
      strcpy(month_desc, "October");
    } else if (month == 11) {
      strcpy(month_desc, "Novenber");
    } else if (month == 12) {
      strcpy(month_desc, "December");
    } else {
      printf("Invalid input. Please try again.\n");
      continue;
    }

    // Output result
    printf("\t%d\t %.3s\n",month, month_desc);
  }
  return 0;
}