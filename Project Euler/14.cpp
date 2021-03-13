#include "gmacro.h"
#include <iostream>
long long GetCollatzLength(long long number)
{
	long long cur = number;
	long long count = 1;
	while (cur != 1) {
		if (cur % 2 == 0)
			cur /= 2;
		else
			cur = 3 * cur + 1;
		++count;
	}
	return count;
}
int main()
{

	int x = 3;
	

	long long max_length = 0;
	long long max_number = 0;
	for (long long i = 1; i < 1000000; ++i)
	{
		auto x = GetCollatzLength(i);
		if (max_length < x)
		{
			max_number = i;
			max_length = x;
		}
	}
	std::cout << max_number;
}


