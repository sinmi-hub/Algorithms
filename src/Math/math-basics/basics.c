#include "basics.h"

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

/* Precondition:    num1 is positive or negative
*                   num2 is positive or negative
*  Postcondition:   result >= 0
                    returns the greatest common divisor of num1 and num2
*/
unsigned int gcd(int num1, int num2){
    if (num1 == 0 || num2 == 0) {return 0;}
    
    int result = (num1 <= num2) ? abs(num1) : abs(num2);
    while(result >= 1){      
        if (num1 % result == 0 && num2 % result == 0) {break;}
        result--;
    }
    return result;
}

/* Precondition:  num1 >= num2
*  Postcondition: returns the least common multiple of num1 and num2
*/
unsigned int lcm(int num1, int num2){
    return (num1 % num2 == 0) ? num1 : num1 * num2;
}

