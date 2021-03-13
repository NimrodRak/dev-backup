#include "gmacro.h"

#define SUP 1000

int inline quadratic_value(int n, int a, int b) { return n*n + a*n + b; }

bool is_prime(int number)
{
    for (int i = 2; i < number / 2 + 1; ++i)
        if (number % i == 0)
            return false;
    
    return true;
}

int consecutive_primes(int a, int b)
{
    int n = 0;
    for (; is_prime(quadratic_value(n, a, b)); ++n); // as long as we are still getting prime numbers from the equation

    return n - 1;
}

int main()
{
    
    int max_consecutives = 0;
    long max_coeffs = 0;
    
    for (int a = -SUP + 1; a < SUP; ++a)
    {
        for (int b = -SUP; b <= SUP; ++b)
        {
            auto cur = consecutive_primes(a, b);
            if (cur > max_consecutives)
            {
                log(cur << ' ' << a << ' ' << b);
                max_consecutives = cur;
                max_coeffs = a * b;
            }
        }
    }
        
    log(max_coeffs);
}