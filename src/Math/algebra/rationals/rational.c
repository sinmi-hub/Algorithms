#include "rational.h"

/*It is assumed that denominator != 0*/

rational_t absolute(rational_t r){
    rational_t result = {abs(r.numerator), abs(r.denominator)};
    return reduce(result);
}

rational_t reduce(rational_t r1){
    int val = gcd(r1.numerator, r1.denominator);
    val = (val == 0) ? 1 : abs(val); // set val = 1 if 0 to prevent division err
    
    /* adjust neg sign in scenario that negative sign is in denominator.
     * In case that num and denom are both neg, the rational num is pos
     * negative sign will be moved to numerator, if found in denominator
    */
    if(r1.denominator < 0){
        r1.numerator = (r1.numerator > 0) ? -r1.numerator : abs(r1.numerator);
        r1.denominator = abs(r1.denominator);
    }
    
    /* reduction begins here
     * reduction of (0 / any number) is (0 / 1) 
     * i.e. 0/5 = 0/1, 0/2 = 0/1 .. etc
     */
    if (r1.numerator == 0)
         return (rational_t){.numerator = 0, .denominator = 1};
    else
        return (rational_t){.numerator=r1.numerator / val, .denominator=r1.denominator / val};
}

rational_t add(rational_t r1, rational_t r2){
    rational_t result = {(r1.numerator * r2.denominator) + (r2.numerator * r1.denominator), (r1.denominator * r2.denominator)};
    return reduce(result);
}

rational_t subtract(rational_t r1, rational_t r2){
    rational_t result = {(r1.numerator * r2.denominator) - (r2.numerator * r1.denominator), (r1.denominator * r2.denominator)};
    return reduce(result);
}

rational_t multiply(rational_t r1, rational_t r2){
    rational_t result = {(r1.numerator * r2.numerator), (r1.denominator * r2.denominator)};
    return reduce(result);
}

rational_t divide(rational_t r1, rational_t r2){
    return reduce((rational_t){.numerator=r1.numerator * r2.denominator, .denominator=r1.denominator * r2.numerator});
}

rational_t exp_rational(rational_t r1, int16_t n){
    int16_t numerator = (int)pow(r1.numerator, abs(n));
    int16_t denominator = (int)pow(r1.denominator, abs(n));
    rational_t val = {numerator, denominator};
    if (n < 0)
        return reduce((rational_t){.numerator=denominator, .denominator=numerator});
    return reduce(val);  
}

float exp_real(uint16_t x, rational_t r1){
    float num = (float)r1.numerator / r1.denominator;
    return pow(x, num);
}
