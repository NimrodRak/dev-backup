#include <iostream>

static int array[101];
static void solve(int t)
{
	unsigned int n, a, b, c;
	std::cin >> n >> a >> b >> c; 

	if (n < a || n < b || n < c || a + b < c)
	{
		std::cout << "Case #" << t << ": IMPOSSIBLE" << std::endl;
		return;
	}
	for (int i = 0; i < a - 1; ++i)
		array[i] = 1;
	array[a - 1] = n;

	for (int i = n; i >= b; --i)
		array[i] = 1;
	if (b != n)
		array[n - b - 1] = n;
	
	for (int i = 0; i < c; ++i)
		array[i + a - 1] = n;
	for (int i = a + c - 1; i < b; ++i)
		array[i] = 1;

	std::cout << "Case #" << t << ": ";
	for (int i = 0; i < n; ++i)
		std::cout << array[i] << ' ';
	std::cout << std::endl;

}

int main_old_high()
{
	int t, i = 0;
	std::cin >> t;
	while (i++ < t)
		solve(i + 1);
	return 0;
}