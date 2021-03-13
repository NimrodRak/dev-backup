#include "presets.h"
#include <vector>
bool is_prime(const int number)
{
    for (int i = 2; i < number / 2 + 1; ++i)
        if (number % i == 0)
            return false;
    
    return true;
}

std::vector<int> get_digits(int i)
{
    std::vector<int> digits;
    while (i != 0)
    {
        digits.push_back(i % 10);
        i /= 10;
    }
    return digits;
}

bool is_permutation(std::vector<int> lhs, std::vector<int> rhs)
{
    for (auto& l : lhs)
    {
        bool found = false;
        for (int i = 0; i < rhs.size(); ++i)
        {
            if (rhs.at(i) == l)
            {
                rhs.erase(rhs.begin() + i);
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}

bool is_prime_permutation(int i)
{
    std::vector<int> digits = get_digits(i);
    for (int p = 0; p < 3; ++p)
    {
        if (!is_permutation(get_digits(i), digits) || !is_prime(i))
            return false;
        
        i += 3330;
    }
    return true;
}

int main()
{    
    for (int i = 1000; i < 10000; ++i)
    {
        if (is_prime_permutation(i))
            log(i);
    }
}