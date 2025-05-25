/**
 * Practical 8 (week 10) - (C) - Working with Dynamic Arrays - GS
 *
 * Question 3 - A dynamically growing array
 *
 * @file temperatures02.c
 * @brief Reads a batch of temperatures into a dynamically 
 *         growing array and displays in reverse order.
 *
 * This C program performs the following operations:
 *  - Initializes a dynamic array using malloc() with capacity of 5 .
 *  - Prompts to enter temperatures until -100.0.
 *  - When the array is full, copies its existing values
 *      to a new allocated array with double capacity;
 *  - Stores each valid temperature in the array.
 *  - prints all temperatures in reverse order with one decimal place.
 *  - Frees the final array to prevent memory leaks.
 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   2025-05-24
 * @copyright   :   Copyright (c) 2025
 */
#include <stdio.h>   // For printf(), scanf(), getchar()
#include <stdlib.h>  // For malloc(), free()

#define INITIAL_CAPACITY 5
// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int main() {
  // Initialize array size and count
  int capacity = INITIAL_CAPACITY;  // Initial array capacity
  int count = 0;                    // Number of temperatures

  // Allocate initial array
  float* temperatures = (float*)malloc(capacity * sizeof(float));

  // Check allocation success
  if (temperatures == NULL) {
    printf("Memory allocation failed!\n");
    return 1;  // Exit on failure
  }

  float input;  // User input storage

  // Read temperatures until -100.0f
  printf("Please enter temperature #%d (enter -100.0 to finish): ", count + 1);
  while (scanf("%f", &input) == 1 && input != -100.0f) {
    // Resize the array if it's full
    if (count >= capacity) {
      capacity *= 2;
      float* new_temperatures = (float*)malloc(capacity * sizeof(float));
      if (new_temperatures == NULL) {
        printf("Memory allocation failed!\n");
        free(temperatures);
        return 1;
      }
      for (int i = 0; i < count; i++) {
        new_temperatures[i] = temperatures[i];
      }
      free(temperatures);
      temperatures = new_temperatures;
    }

    temperatures[count++] = input;

    // Prompt for the next input
    printf("Please enter temperature #%d (enter -100.0 to finish): ",
           count + 1);
  }

  // Handle invalid input
  if (input != -100.0f) {
    printf("Invalid input, please enter a number (e.g., 23.5).\n");
    clear_input_buffer();
  } else {
    printf("User chose to exit!\n");
  }

  // print heads
  printf("\ntemperatures\t\t\t\toutput\n");

  // Print temperatures in order
  for (int i = 0; i < count; i++) {
    printf("%.1f ", temperatures[i]);
  }
  printf("%.1f\t\t",-100.0f);
  // Print temperatures in reverse
  for (int i = count - 1; i >= 0; i--) {
    printf("%.1f ", temperatures[i]);  // One decimal place
  }
  printf("\n");

  // Free final array
  free(temperatures);

  return 0;  // Success
}