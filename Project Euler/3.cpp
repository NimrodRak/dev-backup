#include <iostream>
#include <vector>
void inline MaxOut(long long& site, long long other) { if (site < other) site = other; }
long long Factorize(long long num)
{
	long long original = num;
	long long max = 0;
	for (long long i = 2; i < original && num != 1; ++i)
		if (num % i == 0)
		{
			num /= i;
			MaxOut(max, Factorize(i));
		}
	if (max == 0) return num; else return max;
}

#if 0
int main()
{
	while (true)
	{
		long long num; std::cin >> num;
		std::cout << "Soulution: " << Factorize(num) << std::endl;
	}
	
}
#endif