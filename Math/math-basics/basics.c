#include "basics.h"

/* limit here is used to describe how the nth multiple of parameter, "num"*/
unsigned int *find_multiples(unsigned int num, int n) {
    if (num == 0 || n == 0)
        return NULL;
    
    int size = floor((n - 1) / num);
    unsigned int *result = calloc(size, sizeof(unsigned int));
    
    for (int i = 0; i < size; i++) {
        result[i] = num * (i + 1);
    }
    
    return result;
}

unsigned int sum_of_squares(unsigned int number){
    unsigned int result = 0;
    while(number > 0){
       result += (number * number);
       number--;
    }
    return result;
}

unsigned int square_of_sum(unsigned int number){
    return (((number *(number + 1)) / 2)) * ((number *(number + 1)) / 2);
}

