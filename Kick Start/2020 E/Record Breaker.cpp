#include <iostream>

static int array[200001];
static void solve(const int case_num)
{
	int n, prev = -1, breakers = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> array[i];

	for (int i = 0; i < n; ++i)
	{

		if (array[i] > prev && (i == n - 1 || array[i] > array[i + 1]))
			++breakers;
		prev = std::max(array[i], prev);
	}
	std::cout << "Case #" << case_num << ": " << breakers << std::endl;

}

int main_record()
{
	int T; std::cin >> T;
	for (int i = 0; i < T; ++i)
		solve(i + 1);
	return 0;
}