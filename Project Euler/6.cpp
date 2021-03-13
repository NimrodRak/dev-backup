#define CURRENT 0
#include <iostream>
#if CURRENT
#include <cmath>

int main()
{
	long double square_sum = 0, sum = 0;
	for (auto i = 1; i <= 10; ++i)
	{
		square_sum += pow(i, 2);
		sum += i;
	}
	std::cout << std::fixed << pow(sum, 2) - square_sum << std::endl;
	std::cin.get();

}
#endif