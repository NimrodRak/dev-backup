#define CURRENT 0
#include <iostream>

#if CURRENT
int main()
{
	unsigned int i = 1;
	while (true)
	{
		auto found = true;
		for (auto j = 1; j <= 20; ++j)
		{
			if (i % j != 0)
			{
				found = false;
				break;
			}
		}
		//std::cout << i << std::endl;
		if (found)
			break;
		++i;
	}
	std::cout << i << std::endl;
	std::cin.get();
}
#endif