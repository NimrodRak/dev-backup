#define CURRENT 0
#if CURRENT
#include <iostream>
const int SIZE = 1000;

bool Pythagorean(const int a, const int b, const int c) { return a * a + b * b == c * c; }

int main()
{
	for (auto c = 0; c < SIZE; ++c)
	{
		std::cout << c << std::endl;
		for (auto b = 0; b < c; ++b)
		{
			for (auto a = 0; a < b; ++a)
			{
				if (a + b + c == SIZE)
				{
					if (Pythagorean(a, b, c))
					{
						std::cout << a << ' ' << b << ' ' << c << ": " << a * b * c;
						std::cin.get();
					}
				}
			}
		}
	}
	std::cout << "end";
}
#endif