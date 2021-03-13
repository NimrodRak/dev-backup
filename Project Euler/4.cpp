#include <iostream>
#include <stack>
void inline MaxOut(int& site, int other) { if (site < other) site = other; }

bool IsPalindrom(int num)
{
	int temp = num;
	std::stack<int> digits;
	auto num_of_digits = 0;
	while (temp > 0)
	{
		++num_of_digits;
		temp /= 10;
	}
	temp = num;
	for (auto i = 0; i < num_of_digits / 2; ++i)
	{
		digits.push(temp % 10);
		temp /= 10;
	}
	if (num_of_digits % 2 == 1)
		temp /= 10;
	
	while (!digits.empty())
	{
		
		if (temp % 10 != digits.top())
			return false;
		digits.pop();
		temp /= 10;
	}
	return temp == 0;
}
#if 0
int main()
{
	IsPalindrom(30);
	int max = 0;
	for (auto i = 0; i < 1000; ++i)
	{
		for (auto j = 0; j < 1000; ++j)
		{
			if (IsPalindrom(i * j))
				MaxOut(max, i * j);
		}
	}
	std::cout << max;
		
}
#endif