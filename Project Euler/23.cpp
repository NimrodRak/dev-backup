#include "gmacro.h"
#include <vector>
#include <map>

#define SUP 28124

bool is_abundant(int number)
{
    int total = 0;
    for (size_t i = 1; i < number / 2 + 1; ++i)
        if (number % i == 0)
            total += i;
    return total > number;
}


bool is_abundants_sum(int sum, std::vector<int>& cache)
{
    for (auto& ab1 : cache)
        for (auto& ab2 : cache)
            if (ab1 + ab2 == sum)
                return true;
    return false;
}


int main()
{
    int non_abundant_sum = 0;

    std::vector<int> abundant_cache; // vector of all abundants

    for (size_t i = 1; i < SUP; ++i)
    {
        if (i % 1000 == 0) log(i);
        if (is_abundant(i))
            abundant_cache.push_back(i);
        if (!is_abundants_sum(i, abundant_cache))
            non_abundant_sum += i;
    }
    for (auto x : abundant_cache)
        std::cout << x << ' ';
    std::cout << std::endl << "tot:" << non_abundant_sum;;
}