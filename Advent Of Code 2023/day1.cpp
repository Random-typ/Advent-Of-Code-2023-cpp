#include "adventOfCode.h"

void day1() {
	std::fstream fs("input/day1.txt");
	checkFile;

	int count = 0;
	for (std::string line; std::getline(fs, line); )
	{
		if (line.find_first_of("0123456789") == std::string::npos)
		{
			continue;
		}
		count += std::stoi(std::string{ line[line.find_first_of("0123456789")], line[line.find_last_of("0123456789")] });
	}
	fs.close();

	std::cout << "Day1: " << count << "\n";
}

void day1Part2()
{
	std::fstream fs("input/day1.txt");
	checkFile;

	std::vector<std::string> numbers{
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	int count = 0;
	auto findFirst = [&numbers](std::string& str) -> char {
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				return str[i] - '0';
			}
			for (size_t j = 0; j < numbers.size(); j++)
			{
				if (str.size() - i >= numbers[j].size() && !memcmp(&str[i], numbers[j].data(), numbers[j].size()))
				{
					return j + 1;
				}
			}
		}
		};

	auto findLast = [&numbers](std::string& str) -> char {
		for (int i = str.size() - 1; i >= 0 ; i--)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				return str[i] - '0';
			}
			for (size_t j = 0; j < numbers.size(); j++)
			{
				if (str.size() - i >= numbers[j].size() && !memcmp(&str[i], numbers[j].data(), numbers[j].size()))
				{
					return j + 1;
				}
			}
		}
		};

	for (std::string line; std::getline(fs, line); )
	{
		int i = std::stoi(std::string{ char('0' + findFirst(line)), char('0' + findLast(line)) });
		count += i;
	}
	fs.close();

	std::cout << "Day1 Part2: " << count << "\n";
}
