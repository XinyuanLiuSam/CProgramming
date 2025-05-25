/**
 * Practical 8 (week 10) - (C) - Working with Dynamic Arrays - GS
 *
 * Question 2 - Dynamic odds-and-evens
 *
 * @file odds_evens01.c
 * @brief Reads integers and prints odds and evens in separate arrays.
 *
 * This C program:
 *      - Reads number of integers and allocates array with malloc().
 *      - Reads integers into the array.
 *      - Counts odd and even numbers.
 *      - Allocates arrays for odd and even numbers with exact sizes.
 *      - Copies odd and even numbers to respective arrays.
 *      - Prints odd numbers, then even numbers, separated by spaces.
 *      - Frees all allocated memory.
 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   2025-05-24
 * @copyright   :   Copyright (c) 2025
 */

#include <stdio.h>   // For printf(), scanf()
#include <stdlib.h>  // For malloc(), free()

int main() {
  // Read number of integers
  int num_int;
  printf("Enter the number of integers: ");
  if (scanf("%d", &num_int) != 1 || num_int <= 0) {
    printf("Invalid number of integers, must be positive.\n");
    return 1;
  }

  // Allocate array for integers
  int* integers = (int*)malloc(num_int * sizeof(int));
  if (integers == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // prompt user to input integers
  // Count odd and even numbers
  int odd_count = 0;
  int even_count = 0;
  for (int i = 0; i < num_int; i++) {
    printf("Please enter integer %d of %d for array[%d]: ", i + 1, num_int, i);
    if (scanf("%d", &integers[i]) != 1) {
      printf("Invalid input, please try again.\n");
      // Clear input buffer
      while (getchar() != '\n');
      i--;
      continue;
    }
    if (integers[i] % 2 == 0) {
      even_count++;
    } else {
      odd_count++;
    }
  }

  // Allocate arrays for odd and even numbers
  int* odds = (int*)malloc(odd_count * sizeof(int));
  int* evens = (int*)malloc(even_count * sizeof(int));
  if (odds == NULL || evens == NULL) {
    printf("Memory allocation failed!\n");
    free(integers);
    free(odds);
    free(evens);
    return 1;
  }

  // print heads and input integers
  // Copy odd and even numbers to respective arrays
  printf("\ninput\t\t\toutput\n");
  int odd_index = 0;
  int even_index = 0;
  for (int i = 0; i < num_int; i++) {
    printf("%d ", integers[i]);
    if (integers[i] % 2 == 0) {
      evens[even_index++] = integers[i];
    } else {
      odds[odd_index++] = integers[i];
    }
  }

  printf("\t\t");
  // Print odd numbers
  for (int i = 0; i < odd_count; i++) {
    printf("%d ", odds[i]);
  }
  printf("\n");
  printf("\t\t\t");
  // Print even numbers
  for (int i = 0; i < even_count; i++) {
    printf("%d ", evens[i]);
  }
  printf("\n");

  // Free allocated memory
  free(integers);
  free(odds);
  free(evens);

  return 0;  // Success
}
