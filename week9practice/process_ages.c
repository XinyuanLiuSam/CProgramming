
/**
 * Practical 7 (week 9) - (C ) Arrays and Iteration - GS
 *
 * Question 2 - Reading Ages
 *
 * @file process_ages.c
 * @brief reads a batch of age inputs, calculates and displays
 *        the maximum, minimum, and average for each batch.
 *
 * This C program performs the following operations:
 * - Repeatedly accepts age inputs (up to 10 per batch) from the user
 * - Allows early termination of a batch by entering `-1`
 * - Validates that all ages are within a reasonable range (1–149)
 * - For each batch of valid inputs:
 *    - Calculates and display the maximum, minimum, and average age
 * - Supports multiple rounds of input and analysis until the user quits(entering `q` or `Q`)
 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   2025-05-14
 * @copyright   :   Copyright (c) 2025
 */

#include <stdio.h>   // For printf(), scanf()
#include <stdlib.h>  // For atoi()
#include <string.h>  // For strcpy()

int main(void) {
  // Define and initialize the original array of numbers
  int ages[10];    // Array to store up to 10 ages per batch
  char input[10];  // String input buffer to handle age or command

  while (1) {
    printf("\n--- start new age process ---\n");
    int count = 0;  // Count of valid ages entered in this batch

    // Read up to 10 valid ages or stop early if user inputs -1
    while (count < 10) {
      printf("Enter age[0-150] for person %d. (-1 to end enter, q for quit):",
             count + 1);
      // Read the input as string from user
      if (scanf("%s", input) != 1) {
        printf("Input error. Please try again.\n");
        continue;
      }

      // Exit program if user enters 'q' or 'Q'
      if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0) {
        printf("Exiting program.\n");
        return 0;
      }

      // Convert input string to integer
      int age = atoi(input);  // conver string to digit

      // Check for quit command
      if (age == -1) {
        break;
      }

      // Check if input is within valid range
      if (age < 0 || age > 150) {
        printf("Input error. Please try again.\n");
        continue;
      }
      // Store valid age and increment counter
      ages[count] = age;
      count++;
    }

    // get max, min and avg ages 
    int min = ages[0];
    int max = ages[0];
    float sum = 0.0;
    for (int i = 0; i < count; i++) {
      sum += ages[i];  // Add to sum; 
      // sum = sum + ages[i];

      if (min > ages[i]) {
        min = ages[i];  // Update minimum age
      }
      if (max < ages[i]) {
        max = ages[i];  // Update maximum age
      }
    }
    // Calculate average age as float.
    float avg = sum / count;

    // print to display input, and then display max, min and avg ages.
    printf("\ninput\t\t\t\tmaximum\tminimum\taverage\n");
    for (int i = 0; i < count; i++) {  // display input ages;
      printf("%d ", ages[i]);
    }
    printf("\t%d\t%d\t%.2f\n", max, min, avg);

  }
  return 0;  // Exit program normally
}