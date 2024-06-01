#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

float division(float Number_One, float Number_Two){
    if (Number_Two == 0) {
        perror("Division by zero");
        exit(1);
    }
    return Number_One / Number_Two;
}