#include "armstrong_numbers.h"

bool is_armstrong_number(int candidate){
    if (candidate < 0) {return false;}
    
    int num_digits = 0, result = 0, temp = candidate;
    while(temp){
        temp /= 10;
        num_digits++;
    }
    temp = candidate;
    
    while(temp){
        int digit = temp % 10;
        result += pow(digit, num_digits);
        if (result > candidate) {return false;}
        temp /= 10;
    }
    
    return ((result == candidate) ? true : false);
}