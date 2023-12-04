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

	std::vector<std::pair<std::string, size_t/* copy count */>> cards;
	
	for (std::string line; std::getline(fs, line);)
	{
		cards.emplace_back(line, 1);
	}
	int totalCount = cards.size();
	for (size_t i = 0; i < cards.size();)
	{
		size_t off = cards[i].first.find(':');
		std::vector<int> winningNumbers;
		std::vector<int> numbers;

		while (true)
		{
			off = cards[i].first.find_first_of("0123456789|", off + 1);
			if (cards[i].first[off] == '|')
			{
				break;
			}
			size_t end = cards[i].first.find_first_not_of("0123456789", off);
			winningNumbers.emplace_back(std::stoi(cards[i].first.substr(off, end - off)));
			off = end;
		}
		while (off != std::string::npos)
		{
			off = cards[i].first.find_first_of("0123456789", off + 1);
			if (off == std::string::npos)
			{
				break;
			}
			size_t end = cards[i].first.find_first_not_of("0123456789", off);
			numbers.emplace_back(std::stoi(cards[i].first.substr(off, end - off)));
			off = end;
		}
		
		int copyCount = 0;
		for (auto& i : numbers)
		{
			for (auto& j : winningNumbers)
			{
				if (j != i)
				{
					continue;
				}
				copyCount++;
			}
		}
		if (!copyCount)
		{// this is just for speed
			cards[i].second = 0;
			i++;
			continue;
		}
		totalCount += copyCount;
		for (size_t j = i + 1; j < i + copyCount + 1 && j < cards.size(); j++)
		{
			cards[j].second++;
		}
		cards[i].second--;
		if (!cards[i].second)
		{
			i++;
		}
	}

	std::cout << "Day4 : " << totalCount << "\n";
}
