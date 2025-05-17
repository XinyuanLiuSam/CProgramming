/**
 * Practical 7 (week 9) - (C ) Arrays and Iteration - GS
 *
 * Question 1 - Array processing
 *
 * @file        odd_evens.c
 * @brief   separates even and odd numbers from the nums array into
 *          evens and odds arrays and prints them.
 *
 *
 * This C program:
 *  - declares an array of ints called nums containing the numbers:
 *  - 11, 3, 9, 7, 6, 10, 13, 17, 2, 8, 3
 *  - and declares two more integer arrays called evens and odds with length 11.
 *  - Then copy all of the even numbers in nums (in order) to evens
 *  - and all the odd numbers of nums to the odds array.
 *  - print the values added to the evens and odds arrays

 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   17/05/2025
 * @copyright   :   Copyright (c) 2025
 */
#include <stdio.h>   // For printf(), scanf()
#include <stdlib.h>  // For atoi()
#include <string.h>  // For strcpy()
int main(void) {
  int nums[] = {61, 34, 11, 77, 67, 101, 17, 22, 8};
  int evens[11], odds[11];
  // calculate the number in the nums array;
  int count = sizeof(nums) / sizeof(nums[0]);
  // counters for evens array and odds array;
  int evens_count = 0, odds_count = 0;
  printf("\nnums\t\t\t\todds\t\t\tevens\n");

  for (int i = 0; i < count; i++) {
    if (nums[i] % 2 == 0) {
      // even number: add to evens array;
      evens[evens_count++] = nums[i];
    } else {
      // odd number: add to odds array;
      odds[odds_count++] = nums[i];
    }
    // print each number in original array;
    printf("%d ", nums[i]);
  }

  // print a tab and the odds numbers;
  printf("\t");
  for (int i = 0; i < odds_count; i++) {
    printf("%d ", odds[i]);
  }

  // print a tab and the evens numbers;
  printf("\t");
  for (int i = 0; i < evens_count; i++) {
    printf("%d ", evens[i]);
  }

  printf("\n");
  return 0;
}