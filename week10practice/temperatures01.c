/**
 * Practical 8 (week 10) - (C) - Working with Dynamic Arrays - GS
 *
 * Question 1 - Reading into a dynamic array. 
 *
 * @file temperatures01.c
 * @brief reads a batch of temperature inputs and displays them in reverse order.
 *
 * This C program performs the following operations:
 * - reads a (non-empty) sequence maximum daily temperatures. 
 * - using malloc(), dynamically allocate an array just big enough to hold the number of temperatures. 
 * - then read in the elements of the array using a loop.  
 * - print out the elements of the array in reverse order with 1 decimal point of precision. 
 * - Supports multiple rounds of input and analysis until the user quits(entering `q` or `Q`)
 * 
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   2025-05-14
 * @copyright   :   Copyright (c) 2025
 */

#include <stdio.h>   // For printf(), scanf()
#include <stdlib.h>  // For atoi(), malloc(), free()
#include <ctype.h>   // For getchar()

// Function to clear input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char input[10];
    int num_temps;
    float *temps;

    while (1) {
        // Prompt for number of temperatures or quit
        printf("Please enter a positive number (integer) of temperatures (or 'q'/'Q' to quit): ");
        scanf("%s", input);
        clear_input_buffer(); // Clear buffer after reading input

        // Check for quit condition
        if (input[0] == 'q' || input[0] == 'Q') {
            printf("Exiting program.\n");
            break;
        }

        // Convert input to integer and validate
        num_temps = atoi(input);
        if (num_temps <= 0) {
            printf("Invalid number, Please try again.\n");
            continue;
        }

        // Allocate memory for num_temps temperatures
        temps = (float *)malloc(num_temps * sizeof(float));
        if (temps == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Read temperatures with validation
        printf("Enter %d temperatures:\n", num_temps);
        for (int i = 0; i < num_temps; i++) {
            int valid_input = 0;
            while (!valid_input) {
                printf("Enter temperature %d of %d (temperatures[%d]): ", i + 1, num_temps, i);
                if (scanf("%f", &temps[i]) == 1) {
                    valid_input = 1;
                } else {
                    printf("Invalid input. Please enter a valid float.\n");
                    clear_input_buffer(); // Clear buffer for invalid input
                }
            }
        }

        // Print table head
        printf("\ncount\ttemperatures\t\t\toutput\n");

        // Print number of temperatures 
        printf("%d\t", num_temps);

        // Print temperatures in order
        for (int i = 0; i < num_temps; i++) {
            printf("%.1f ", temps[i]);
        }

        printf("\t\t");

        // Print temperatures in reverse order
        for (int i = num_temps - 1; i >= 0; i--) {
            printf("%.1f ", temps[i]);
        }
    
        printf("\n");

        // Free allocated memory
        free(temps);
    }

    return 0;
}