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

void day2()
{
	std::fstream fs("input/day2.txt");
	checkFile;

	int count = 0;
	const int redMax = 12;
	const int greenMax = 13;
	const int blueMax = 14;
	size_t gameOffset = std::string("Game ").length();
	for (std::string line; std::getline(fs, line); )
	{
		size_t off = line.find(':');
		int gameN = std::stoi(line.substr(gameOffset, gameOffset - off));

		int redCount = 0,
			greenCount = 0,
			blueCount = 0;
		for (off = line.find_first_of("0123456789", off); off != std::string::npos; off = line.find_first_of("0123456789", off))
		{
			size_t end = line.find_first_not_of("0123456789", off);
			size_t cubeCount = std::stoi(line.substr(off, end - off));
			off = line.find_first_not_of(' ', end);
			switch (line[off])
			{
			case 'r':
				redCount += cubeCount;
				break;
			case 'g':
				greenCount += cubeCount;
				break;
			case 'b':
				blueCount += cubeCount;
				break;
			}
			if (size_t setEnd = line.find_first_of(";,", off); setEnd == std::string::npos || line[setEnd] == ';') {
				if (redCount > redMax || greenCount > greenMax || blueCount > blueMax)
				{
					break;
				}
				redCount = 0;
				greenCount = 0;
				blueCount = 0;
			}
		}
		if (redCount <= redMax && greenCount <= greenMax && blueCount <= blueMax)
		{
			count += gameN;
		}
	}

	std::cout << "Day2: " << count << "\n";
}

void day2Part2()
{
	std::fstream fs("input/day2.txt");
	checkFile;

	int count = 0;
	size_t gameOffset = std::string("Game ").length();
	for (std::string line; std::getline(fs, line); )
	{
		size_t off = line.find(':');
		int redCount = 0,
			greenCount = 0,
			blueCount = 0;
		for (off = line.find_first_of("0123456789", off); off != std::string::npos; off = line.find_first_of("0123456789", off))
		{
			size_t end = line.find_first_not_of("0123456789", off);
			size_t cubeCount = std::stoi(line.substr(off, end - off));
			off = line.find_first_not_of(' ', end);
			switch (line[off])
			{
			case 'r':
				redCount = cubeCount > redCount ? cubeCount : redCount;
				break;
			case 'g':
				greenCount = cubeCount > greenCount ? cubeCount : greenCount;
				break;
			case 'b':
				blueCount = cubeCount > blueCount ? cubeCount : blueCount;
				break;
			}
		}
		count += redCount * greenCount * blueCount;
	}

	std::cout << "Day2 Part2: " << count << "\n";
}
