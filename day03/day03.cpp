#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

#include "utils.hpp"

int main()
{
	std::vector<std::string> fileLines;
	try
	{
		fileLines = readFile("/home/nick/aoc23/day03/test_data.txt");
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	std::vector<int> v;
	v.push_back(4);
	int a = v[4];

	return 0;
}
