#define CURRENT 0
#if CURRENT
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using matrix = std::vector<std::vector<int>>;

void inline Maximize(long long& max, const long long number) { if (number > max) max = number; }
long long GetMult(const matrix& v, const int x, const int y, const short xChange, const short yChange, const int length)
{
	if (xChange == 0 && yChange == 0)
		return 0;
	long long product = 1;
	for (auto i = 0; i < length; ++i)
	{
		const auto new_x = x + i * xChange;
		const auto new_y = y + i * yChange;
		if (new_x >= 0 && new_x < v.size()
			&& new_y >= 0 && new_y < v.at(0).size())
			product *= v.at(new_x).at(new_y);
		else
			return 0;
	}
	return product;
}

matrix GetMatrix()
{
	matrix v;
	std::fstream file(R"x(Source Files\11.txt)x");
	std::string temp;
	while (std::getline(file, temp))
	{
		std::stringstream ss(temp);
		v.emplace_back();
		std::string cur;
		while (std::getline(ss, cur, ' '))
			v.back().push_back(std::stoi(cur));
	}
	return v;
}
int main()
{
	matrix v = GetMatrix();
	short changes[] = { -1, 0, 1 };
	/* x is row number starting from 0 at the top going down
	 * y is column number starting from 0 at the left doing right
	 */
	long long max = 0;
	int *maxed = new int[4];
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < v.at(0).size(); ++j)
			for (auto xChange : changes)
				for (auto yChange : changes)
				{
					const auto num = GetMult(v, i, j, xChange, yChange, 4);
					Maximize(max, num);
					if (max == num)
					{
						std::cout << "new max: " << i << ' ' << j << ' ' << xChange << ' ' << yChange << ' ' << max << std::endl;
					}
				}
	std::cout << max << std::endl;
	
	std::cin.get();
}


#endif
