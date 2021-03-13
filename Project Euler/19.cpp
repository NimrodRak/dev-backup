#include "gmacro.h"
#include <algorithm>
#include <chrono>
bool inline is_leap_year(const int year)
{
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			return false;
		}
		return true;
	}
	return false;
}
static short first_days[] = { 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 };
bool is_first_of_month(short day, bool leap)
{
	if (day == 1 || day == 32)
		return true;
	
	if (leap)
		--day;

	return std::find(first_days, first_days + 11, day) != first_days + 11;
}


int main()
{
	
	return 0;
	long day = 7; // first sunday was 7/1/1000
	long total = 0;
	for (size_t year = 1901; year <= 2000; ++year)
	{
		bool leap = is_leap_year(year);
		if (leap)
			std::cout << year << " leap " << leap << std::endl;
		auto year_length = 365 + (leap ? 1 : 0);
		for (; day <= year_length; day += 7)
		{
			if (year == 1924)
				std::cout << year << ' ' << day << std::endl;

			if (is_first_of_month(day, leap))
			{
				++total;
				std::cout << year << ' ' << day << std::endl;
			}
			
		}
		day %= year_length;
	}
	log(total);
}
