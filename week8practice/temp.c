#include <stdio.h>

int main(void) {
    int temp_cels;
    int temp_fahr;
    printf("enter a degree in celsius:");
    scanf("%d",&temp_cels);
    temp_fahr=temp_cels*9/5+32;
    printf("%d degrees Celsius is %d degrees Fahrenheit.\n",temp_cels,temp_fahr);
    return 0;
}