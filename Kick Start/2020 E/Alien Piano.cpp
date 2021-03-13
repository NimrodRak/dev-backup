#include <iostream>
static int array[10001];

static void solve(int case_num)
{
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> array[i];

	short up = 0, down = 0;
	int bad = 0;

	for (int i = 1; i < n; ++i)
	{
		
		if (array[i] > array[i - 1])
		{
			++up;
			down = 0;
		}
		
		else if (array[i] < array[i - 1])
		{
			++down;
			up = 0;
		}

		if (up > 3 || down > 3)
		{
			++bad;
			up = 0;
			down = 0;
		}
	}
		
	std::cout << "Case #" << case_num << ": " << bad << std::endl;
}

int main_alien()
{
	int T; std::cin >> T;
	for (int i = 0; i < T; ++i)
		solve(i + 1);
}