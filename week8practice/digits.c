/**
 * @Practical 6 (week 8)
 *
 * Question 4 - Extracting digits
 *
 * @file        digits.c
 * @brief       Read a three-digit positive integer, extract and 
 *              display its hundreds, tens, and ones digits. Allows quitting with 'q'.
 *
 * This C program:
 * - Reads a positive three-digit integer from user input.
 * - Extracts and displays the ones (units), tens, and hundreds digits on separate lines.
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
int main(void){
    char input[20];      // buffer to hold user input (string)
    int digit_input;
                                    
    // Input validation: keep prompting until a valid three-digit number is entered
    while (1) {
        printf("Please enter a three-digit integer (or 'q' to quit): ");
        scanf("%s", input);  // read input as string

        // Check if user wants to quit
        if (strcmp(input, "q") == 0 ) {
            printf("Exiting program.\n");
            exit(0);  // exit the program
        }

        digit_input = atoi(input);  // convert to int

        // Check if the input is a valid three-digit number
        if (digit_input >= 100 && digit_input <= 999) {

            int ones = digit_input % 10;
            int tens = (digit_input / 10) % 10;
            int hundreds = digit_input / 100;
        
            printf("The results are:\n");        
            printf("%8d\t%8d\n",digit_input,ones);
            printf("\t\t%8d\n",tens);
            printf("\t\t%8d\n",hundreds);
        } else {
            printf("Invalid input. Please try again!\n");
            continue;
        }
    }
    return 0;
}