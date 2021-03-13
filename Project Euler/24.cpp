#include "gmacro.h"
#include <vector>
#include <algorithm>
#include <string>

int main()
{
    std::string s = "0123456789";
    int prev = 0;
    for (size_t i = 0; i < 999999; ++i)
    {
        std::next_permutation(s.begin(), s.end());
    }
    log(s);
}