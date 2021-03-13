#include "presets.h"
#include <cmath>
static const int substrlen = 3;
static const int primes[] = { 2, 3, 5, 7, 11, 13, 17 };

bool is_substring_divisble(unsigned long long number)
{
    int substring = number % (int) pow(10, substrlen);
    number /= pow(10, substrlen);
    for (int i = 7; i >= 0; --i, number /= 10)
    {
        if (substring % primes[i] != 0)
            return false;
        substring = substring / 10 + pow(10, substrlen - 1) * (number % 10);
    }
    return true;
}

int main()
{
    log(is_substring_divisble(1406357289));
    return 0;
    for (int i = pow(10, 9); i < pow(10, 10); ++i)
        if (is_substring_divisble(i))
            std::cout << i << std::endl;
}