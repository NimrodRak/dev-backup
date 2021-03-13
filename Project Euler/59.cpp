#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#define CURRENT 0
static const std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; 
static const double AverageSpaceFrequency = 30;
bool validate(std::vector<char>& converted, std::vector<char>& encrypted, std::string password)
{
	short password_index = 0;
	// add in the converted letters
	for (auto letter : encrypted)
	{
		char character = letter ^ password[password_index];
		password_index = ++password_index % 3;
		if (!(std::isprint(character) || std::isspace(character)))
			return false;
		converted.push_back(character);
	}
	
	if (std::count(converted.begin(), converted.end(), ' ') < converted.size() / AverageSpaceFrequency)
		return false;
	// if the string is of common english words, it's the right one
	return true;
}


void solve(std::vector<char>& encrypted)
{
	
	std::string password;
	std::vector<char> converted;
	for (auto letter1 : alphabet)
	{
		password.push_back(letter1);
		for (auto letter2 : alphabet)
		{
			password.push_back(letter2);
			for (auto letter3 : alphabet)
			{
				password.push_back(letter3);
				// the password is now a permutation of a three letter string
				converted.clear();
				if (validate(converted, encrypted, password))
				{
					std::cout << "yay";
					for (auto c : converted)
						std::cout << c;
					std::cout << std::endl;
					std::cin.get();
				}
					
				password.pop_back();
			}
			password.pop_back();
		}
		password.pop_back();
	}
}
#if CURRENT
int main()
{
	int i = 0;

	std::fstream fin;
	fin.open(R"x(C:\dev\Project Euler\Debug\p059_cipher.txt)x", std::ios::in);

	std::string letter;
	std::vector<char> text;
	while (std::getline(fin, letter, ','))
		text.push_back(std::stoi(letter));
	solve(text);

	std::cin.get();
	return 0;
}
#endif