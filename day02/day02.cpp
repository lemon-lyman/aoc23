#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

#include "utils.hpp"

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

int validGame(std::string line, int &power)
{
	std::vector<int> numbers;
	std::istringstream iss(line);
	std::string token;
	int gameId;
	int redMax = 0;
	int grnMax = 0;
	int bluMax = 0;

	iss >> token;
	iss >> gameId;
	iss >> token;

	bool ranOutFlag = false;

	while (std::getline(iss, token, ';'))
	{
		std::istringstream yss(token);
		int number;
		std::string color;
		while (yss >> number >> color)
		{
			// Remove the trailing comma if present
			if (color.back() == ',')
			{
				color.pop_back();
			}

			if (color == "green")
			{
				if (number > grnMax)
				{
					grnMax = number;
				}
				if (number > MAX_GREEN)
				{

					ranOutFlag = true;
				}
			}
			else if (color == "red")
			{
				if (number > redMax)
				{
					redMax = number;
				}
				if (number > MAX_RED)
				{
					ranOutFlag = true;
				}
			}
			else if (color == "blue")
			{
				if (number > bluMax)
				{
					bluMax = number;
				}
				if (number > MAX_BLUE)
				{
					ranOutFlag = true;
				}
			}
		}
	}
	power = grnMax * redMax * bluMax;
	return ranOutFlag ? -1 : gameId;
}

int main()
{
	std::vector<std::string> fileLines;
	try
	{
		fileLines = readFile("/home/nick/aoc23/day02/data.txt");
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	int idSum = 0;
	int pwrSum = 0;
	for (auto line : fileLines)
	{
		int power = 0;
		int result = validGame(line, power);
		if (result != -1)
		{
			idSum += result;
		}
		pwrSum += power;
	}
	std::cout << "idSum: " << idSum << std::endl;
	std::cout << "pwrSum: " << pwrSum << std::endl;

	return 0;
}
