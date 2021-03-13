#define CURRENT 0
#if CURRENT
#include <iostream>

int GetFactorCount(long long number)
{
	int total = 0;
	for (long long i = 1; i < number / 2 + 1; ++i)
		if (number % i == 0)
			++total;
	return total + 1; // also include the number itself
}
const int SUP = 500;
int main()
{
	int count = 0;
	long long num = 0;
	long long sum = 0;
	while (true)
	{
		const int factors = GetFactorCount(sum);
		if (factors > SUP)
			break;
		std::cout << sum << ' ' << factors << std::endl;
		sum += ++num;
	}
	std::cout << "max" << sum;
	std::cin.get();
}

#endif