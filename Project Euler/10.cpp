#define CURRENT 0
#if CURRENT
#include <iostream>

const unsigned long SUP = 2000000;

bool IsPrime(const long long& number)
{
	
	for (auto i = 2; i < number / 2 + 1; ++i)
		if (number % i == 0)
			return false;
	return true;
}

int main()
{
	unsigned long long sum = 0;
	for (unsigned long i = 2; i < SUP; ++i)
		if (IsPrime(i))
			sum += i;
	std::cout << std::fixed;
	std::cout << sum;
	std::cin.get();
}
#endif