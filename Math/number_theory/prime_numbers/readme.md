I find prime numbers to be one of the most interesting mathematical concepts. Almost every technology that we have nowadays, at the very foundation, prime numbers are present. From cryptography to astronomy to even construction!, prime numbers are present

#### size_t prime_factors(uint64_t n, uint64_t factors[MAXFACTORS])

- This function calculates the prime factors of a given number `n` and stores them in the `factors` array. MAXFACTOR is a predefined constant in header file that is set to a default of 100. This function is NOT be considered thread safe since `factors` is declared static.

 *      @param n The number for which prime factors need to be calculated.
 *      @param factors An array to store the prime factors.
 *      @return The number of prime factors found.

#### uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes);

- This function performs the Sieve of Eratosthenes algorithm to find prime numbers within a specific range.
 
 *      @param limit The upper limit of the range to search for prime numbers.(limit is included)
 *      @param primes An array to store the prime numbers found.
 *      @param max_primes The max number of primes to store in the primes array. Length of *primes*
 *      @return The number of prime numbers found within the specified range.
 
 