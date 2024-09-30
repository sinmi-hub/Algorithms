#include "prime.h"


size_t prime_factors(uint64_t n, uint64_t factors[MAXFACTORS]){
    size_t count=0, div = 2;

    while (n>1) {
        if(n % div)
            div += 1;
        else{
            factors[count++] = div;
            n /= div;
        }
    }

    return count;
}

/* Assume limit is 10 & max_primes is 100, this function simply returns 4 because there are only 4 primes between 2 and 10*/
uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes){
    if (limit <= 0 || max_primes <= 0) {return 0;}

    /* scenario where max_primes to find > than limit and vice versa. OYO*/
    int count = 0;
    size_t max_limit = (limit <= max_primes) ? limit + 1 : max_primes * 2;
    
    bool isPrime[max_limit];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;

    for(size_t i = 2; i < max_limit; i++)
    {
        if (i != 2 && i % 2 == 0) {continue;}

        else if (isPrime[i]){
            primes[count++] = i;
            for(size_t j = i * i; j < max_limit; j+=i) {isPrime[j] =  false;}
        }
    }

    return count;
}