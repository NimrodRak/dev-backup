#include <iostream>
static int array[200001];
static void solve(int num)
{
	int number_of_inputs;
	std::cin >> number_of_inputs;

	for (int i = 0; i < number_of_inputs; ++i)
		std::cin >> array[i];

	int length = 1, diff = array[1] - array[0], best = 1;

	for (int i = 1; i < number_of_inputs; ++i)
	{
		if (array[i] - array[i - 1] != diff)
		{
			diff = array[i] - array[i - 1];
			length = 2;
		}
		else
			++length;
		best = std::max(best, length);
	}
	std::cout << "Case #" << num << ": " << best << std::endl;
}

int main_old()
{
	int number_of_cases;
	std::cin >> number_of_cases;
	for (int i = 0; i < number_of_cases; ++i)
		solve(i + 1);
	return 0;
}