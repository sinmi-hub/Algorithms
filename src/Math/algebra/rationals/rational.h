#ifndef RATIONAL_H
#define RATIONAL_H
#include  <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "../../math-basics"

typedef struct{
    int16_t numerator;
    int16_t denominator;
}rational_t;

rational_t absolute(rational_t r);
rational_t reduce(rational_t r1);
rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t exp_rational(rational_t r1, int16_t n);
float exp_real(uint16_t x, rational_t r1);


#endif