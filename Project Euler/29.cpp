#include <iostream>
#include <vector>
#include <cmath>
#define SUP 100
int main()
{
    std::vector<long double> cache;
    for (long double i = 2; i <= SUP; ++i)
        for (long double j = 2; j <= SUP; ++j)
        {
            long double value = pow(i, j);
            std::cout << value << std::endl;
            bool found = false;
            for (auto& x : cache)
                if (x == value)
                {
                    found = true;
                    break;
                }
            if (!found)
                cache.push_back(value);
        }
    std::cout << cache.size();
}