#include "gmacro.h"
#include <vector>
#include <algorithm>
#include <numeric>
int amicable_sum(int number)
{
    int sum = 0;
    for (size_t i = 1; i < number / 2 + 1; ++i)
        if (number % i == 0)
            sum += i;
        
    return sum;
}

int main()
{
    log(amicable_sum(496));
    std::vector<int> amicables;
    for (size_t i = 1; i < 10000; ++i)
    {
        int as = amicable_sum(i);
        if (amicable_sum(as) == i)
        {
            if (as != i && std::find(amicables.begin(), amicables.end(), as) == amicables.end())
            {
                amicables.push_back(as);
                amicables.push_back(i);
            }
        }
    }
    for (auto x : amicables)
        log(x);
    std::cout << std::accumulate(amicables.begin(), amicables.end(), 0);
}