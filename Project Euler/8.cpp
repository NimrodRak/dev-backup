#define CURRENT 0
#if CURRENT
#include <vector>
#include <iostream>
#include <string>

void inline Maximize(long long& max, const long long number) { if (number > max) max = number; }
int main()
{
	const unsigned int length = 13;
	std::string temp;
	std::vector<int> v;

	while (true)
	{
		std::getline(std::cin, temp);
		
		if (temp == "d")
			break;
		for (auto val : temp)
			v.push_back(val - 48);
	}
	
	long long num = 1;
	for (auto i = 0; i < length; ++i)
		num *= v.at(i);
	
	long long max = 0;
	for (auto i = length; i < v.size(); ++i)
	{
		Maximize(max, num);
		//std::cout << num;
		//std::cin.get();
		if (v.at(i - length) == 0)
		{
			num = 1;
			for (auto j = i - length + 1; j < i; ++j)
				num *= v.at(j);
		}
		else
			num /= v.at(i - length);
		num *= v.at(i);

		
	}
	
	std::cout << max;
	std::cin.get();
}
#endif