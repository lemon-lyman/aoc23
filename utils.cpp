#include "utils.hpp"
#include <stdexcept>

std::vector<std::string> readFile(const std::string &filePath)
{
	std::vector<std::string> lines;
	std::ifstream file(filePath);
	std::string line;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			lines.push_back(line);
		}
		file.close();
	}
	else
	{
		throw std::runtime_error("Unable to open file: " + filePath);
	}

	if (lines.size() == 0)
	{
		throw std::runtime_error("File was empty: " + filePath);
	}

	return lines;
}