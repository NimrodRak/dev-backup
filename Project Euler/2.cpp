#include <iostream>
#if 0
int main()
{
	int prev = 0, cur = 1, temp, sum = 0;
	while (cur < 4000000)
	{
		std::cout << cur << std::endl;
		if (cur % 2 == 0)
			sum += cur;
		temp = cur;
		cur += prev;
		prev = temp;
	}
	std::cout << sum;
}
#endif