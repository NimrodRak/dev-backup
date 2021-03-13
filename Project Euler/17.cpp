#define CURRENT 0
#include <map>
#if CURRENT
#include <iostream>

const std::map<int, int> tensMap = {
	{0, 0},
	{1, 3},
	{2, 6},
	{3, 6},
	{4, 5},
	{5, 5},
	{6, 5},
	{7, 7},
	{8, 6},
	{9, 6}
};
const std::map<int, int> onesMap = {
	{0, 0},
	{1, 3},
	{2, 3},
	{3, 5},
	{4, 4},
	{5, 4},
	{6, 3},
	{7, 5},
	{8, 5},
	{9, 4}
};
const std::map<int, int> teensMap = {
	{1, 6},
	{2, 6},
	{3, 8},
	{4, 8},
	{5, 7},
	{6, 7},
	{7, 9},
	{8, 8},
	{9, 8}
};
int GetLength(const int number)
{
	const int one = number % 10, ten = (number / 10) % 10, hundred = number / 100;
	return onesMap.at(hundred) + (hundred != 0 ? 7 : 0) // hundreds count
		+ (hundred != 0 && one + ten != 0 ? 3 : 0) // and
		+ (ten == 1 && one > 0 ? teensMap.at(one) : tensMap.at(ten) + onesMap.at(one)); // add the teens if needed
}
int main()
{
	long long sum = 0;
	for (int i = 1; i < 1000; ++i)
	{
		auto x = GetLength(i);
		std::cout << i << ": " << x << std::endl;
		sum += x;
	}
	
	std::cout << sum + 11;
	std::cin.get();
}

#endif