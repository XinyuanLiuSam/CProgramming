/**
 * @Practical 6 (week 8) - (C)
 *
 * @Question 3 - Form letter
 * @file form_letter.c
 * @brief Accepts personal info and displays a formatted message.
 *
 * This C program prompts the user to enter:
 * - First name and Last name (no more than 10 letters each)
 * - Age in years
 * - Full-time employment fraction (between 0.0 and 1.0)
 * The user can quit by entering 'q' or 'Q' at the first name prompt.
 *
 * @author      :   Xianyuan Liu
 * @student_id  :   a1981985
 * @email       :   xianyuan.liu@student.adelaide.edu.au
 * @date        :   2025-05-09
 * @copyright   :   Copyright (c) 2025
**/
#include <stdio.h>

int main(int argc, char const *argv[]) {
  char first_name[50];
  char last_name[50];
  int age;
  float fraction;
  while(1){
    printf("Enter your name, age and employment fraction[q to quit]:");
    if(scanf("%s",first_name)!=1){
        printf("Input error, please try again.\n");
        continue;

    }
    if(first_name[0]=='q'){
        printf("Program existed!\n");
        break;
        
    }
    if(scanf("%s %d %f",last_name,&age,&fraction)!=3){
        printf("Invalid input,please Enter your name, age and employment fraction[q to quit]:");
        continue;
    }
    printf("Your name is %s %s, you are %d years old and your employment fraction is %.2f.\n ",
    first_name,last_name,age,fraction);
  }
  
  // scanf()
  /* code */
  return 0;
}
