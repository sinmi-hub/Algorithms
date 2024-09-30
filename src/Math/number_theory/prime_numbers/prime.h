#ifndef PRIME_H
#define PRIME_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#define MAXFACTORS 100

//thread safety
size_t prime_factors(uint64_t n, uint64_t factors[static MAXFACTORS]); 
uint32_t sieve(uint32_t lim, uint32_t *primes, size_t max_primes);

#endif