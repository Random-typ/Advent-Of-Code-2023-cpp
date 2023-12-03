#include "adventOfCode.h"

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
