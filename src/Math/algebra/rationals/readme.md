## Rational Numbers
A rational number is defined as the quotient of two integers a and b, called the numerator and denominator, respectively, where b != 0.

### Note
Note that mathematically, the denominator can't be zero. Therefore, in the implementation, it is ASSUMED that 0 cannot be a denominator and is not passed in.

### *Functionalities*
Where *r* is rational number, in form of *a / b*:

- **rational_t absolute(rational_t r);**

    *Absolute Value of Rational Numbers*
    ```
    The absolute value |r| of the rational number r =
    |a| / |b|.
    ```

- **rational_t reduce(rational_t r1);**

    *Reduces Rational Number to its lowest term*
    ```
    ```
- **rational_t add(rational_t r1, rational_t r2);**

    *Sum of Rational Numbers*
    ```
    The sum of two rational numbers r₁ and r₂ =
     (a₁ * b₂ + a₂ * b₁) / (b₁ * b₂).
    ```

- **rational_t subtract(rational_t r1, rational_t r2);**

    *Difference of Rational Numbers*
    ```
    The difference of two rational numbers r₁ and r₂ =  (a₁ * b₂ - a₂ * b₁) / (b₁ * b₂).
    ```

- **rational_t multiply(rational_t r1, rational_t r2);**

    *Multiplication of Rational Numbers*
    ```
    The product of r₁ and r₂ = 
    (a₁ * a₂) / (b₁ * b₂).
    ```

- **rational_t divide(rational_t r1, rational_t r2);**

    *Division of Rational Numbers*
    ```
    Dividing r₁ by r₂ =
    (a₁ * b₂) / (a₂ * b₁) 
    IF a₂ IS NOT ZERO.`
    ```

- **rational_t exp_rational(rational_t r1, int16_t n)**

    *Exponentiation of Rational Numbers*
    ```
    Exponentiation of a rational number r to 
    
    a non-negative integer power n is r^n = (a^n)/(b^n).

    negative integer power n is r^n = (b^|n|)/(a^|n|).
    ```

- **float exp_real(uint16_t x, rational_t r1)**

    *Exponentiation of Real numbers to r*
    ```
    Exponentiation of a real num x to a rational number r = a/b is x^(a/b) 
    ```

### *Dependencies*
- gcd() - functionality to find greatest common denominator found in:
[https://github.com/sinmi-hub/Algorithms/tree/main/Math/math-basics]

- math libary (-lm) to link while compiling