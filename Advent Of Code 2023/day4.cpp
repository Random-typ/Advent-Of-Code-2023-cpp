#include "adventOfCode.h"

void day4() {
	std::fstream fs("input/day4.txt");
	checkFile;

	size_t pointsTotal = 0;
	for (std::string line; std::getline(fs, line);)
	{
		size_t off = line.find(':');
		std::vector<int> winningNumbers;
		std::vector<int> numbers;

		while (true)
		{
			off = line.find_first_of("0123456789|", off + 1);
			if (line[off] == '|')
			{
				break;
			}
			size_t end = line.find_first_not_of("0123456789", off);
			winningNumbers.emplace_back(std::stoi(line.substr(off, end - off)));
			off = end;
		}
		while (off != std::string::npos)
		{
			off = line.find_first_of("0123456789", off + 1);
			if (off == std::string::npos)
			{
				break;
			}
			size_t end = line.find_first_not_of("0123456789", off);
			numbers.emplace_back(std::stoi(line.substr(off, end - off)));
			off = end;
		}

		size_t points = 0;
		for (auto& i : numbers)
		{
			for (auto& j : winningNumbers)
			{
				if (j != i)
				{
					continue;
				}
				if (!points)
				{
					points++;
					continue;
				}
				points *= 2;
			}
		}
		pointsTotal += points;
	}

	std::cout << "Day4: " << pointsTotal << "\n";
}

void day4Part2()
{
	std::fstream fs("input/day4.txt");
	checkFile;

	size_t pointsTotal = 0;
	size_t cardI = 1;
	for (std::string line; std::getline(fs, line); cardI++)
	{
		size_t off = line.find(':');
		std::vector<int> winningNumbers;
		std::vector<int> numbers;

		while (true)
		{
			off = line.find_first_of("0123456789|", off + 1);
			if (line[off] == '|')
			{
				break;
			}
			size_t end = line.find_first_not_of("0123456789", off);
			winningNumbers.emplace_back(std::stoi(line.substr(off, end - off)));
			off = end;
		}
		while (off != std::string::npos)
		{
			off = line.find_first_of("0123456789", off + 1);
			if (off == std::string::npos)
			{
				break;
			}
			size_t end = line.find_first_not_of("0123456789", off);
			numbers.emplace_back(std::stoi(line.substr(off, end - off)));
			off = end;
		}

		size_t points = 0;
		for (auto& i : numbers)
		{
			for (auto& j : winningNumbers)
			{
				if (j != i)
				{
					continue;
				}
				if (!points)
				{
					points++;
					continue;
				}
				points *= 2;
			}
		}
		pointsTotal += points;
	}

	std::cout << "Day4: " << pointsTotal << "\n";

}
