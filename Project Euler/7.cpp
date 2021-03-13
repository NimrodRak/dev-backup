#define CURRENT 0
#if CURRENT
#include <iostream>

bool IsPrime(long long& number)
{
	for (auto i = 2; i < number / 2; ++i)
		if (number % i == 0)
			return false;
	return true;
}

int main()
{
	const auto index = 10001;
	long long num = 2;
	for (auto i = 0; i < index; ++i)
		while (!IsPrime(++num));
	
	std::cout << num << std::endl;
	std::cin.get();
}
#endif