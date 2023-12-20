#include <iostream>
#include <string>
#include <cctype>

#include "day01.hpp"
#include "utils.hpp"

int main()
{
	std::vector<std::string> fileLines;
	try
	{
		fileLines = readFile("/home/nick/aoc23/day01/data.txt");
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	char leftInt;
	char rightInt;
	int sum = 0;
	std::string line;
	for (int il = 0; il < fileLines.size(); il++)
	{
		line = fileLines[il];
		for (auto c : line)
		{
			if (std::isdigit(c))
			{
				leftInt = c;
				break;
			}
		}

		for (int i = line.size(); i > 0; --i)
		{
			if (std::isdigit(line[i]))
			{
				rightInt = line[i];
				break;
			}
		}
		std::string twoDigi = {leftInt, rightInt};
		std::cout << il << ": " << std::stoi(twoDigi) << std::endl;
		sum += std::stoi(twoDigi);
	}

	std::cout << "sum: " << sum << std::endl;
	return 0;
}
