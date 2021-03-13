#include "presets.h"
long long lattice_paths(int size, int i = 0, int j = 0)
{
	if (i == size && j == size)
		return 1;
	
	long long total = 0;

	if (i < size)
		total += lattice_paths(size, i + 1, j);
	if (j < size)
		total += lattice_paths(size, i, j + 1);
	
	return total;
}

int main()
{
	const int size = 20;
	std::cout << lattice_paths(size);
}