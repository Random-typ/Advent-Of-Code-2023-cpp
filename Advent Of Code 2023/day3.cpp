#include "adventOfCode.h"

void day3()
{
	std::fstream fs("input/day3.txt");
	checkFile;

	// build matrix
	std::vector<std::string> matrix;
	for (std::string line; std::getline(fs, line); )
	{
		matrix.emplace_back(line);
	}

	int count = 0;
	
	for (size_t i = 0; i < matrix.size(); i++)
	{
		size_t off = 0;
		while (off != std::string::npos)
		{
			size_t start = matrix[i].find_first_of("0123456789", off);
			if (start == std::string::npos)
			{
				break;
			}
			size_t end = matrix[i].find_first_not_of("0123456789", start);
			int value = std::stoi(matrix[i].substr(start, end - start));
			off = end;
			// check fields around the number

			// check left
			if (start && matrix[i][start - 1] != '.')
			{
				count += value;
				continue;
			}
			// check right
			if (end != std::string::npos && matrix[i][end] != '.')
			{
				count += value;
				continue;
			}
			// check top
			if (start)
			{
				start--;
			}
			if (end >= matrix[i].size())
			{
				end--;
			}
			if (i && matrix[i - 1].substr(start, end + 1 - start).find_first_not_of('.') != std::string::npos)
			{
				count += value;
				continue;
			}

			// check bottom
			if (i + 1 < matrix.size() && matrix[i + 1].substr(start, (end + 1) - start).find_first_not_of('.') != std::string::npos)
			{
				count += value;
				continue;
			}
		}
	}

	std::cout << "Day3: " << count << "\n";
}

void day3Part2()
{
	std::fstream fs("input/day3.txt");
	checkFile;

	// build matrix
	std::vector<std::string> matrix;
	for (std::string line; std::getline(fs, line); )
	{
		matrix.emplace_back(line);
	}
	int count = 0;
	
	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t off = 0;off != std::string::npos; off++)
		{
			int gearCount = 0;
			int gearRatio = 1;
			off = matrix[i].find('*', off);
			if (off == std::string::npos)
			{
				break;
			}
			// check for adjacent numbers

			// check left
			if (off && matrix[i].substr(off - 1, 1).find_first_of("0123456789") != std::string::npos)
			{
				int j = off;
				for (; j > 0 && matrix[i].substr(j - 1, 1).find_first_of("0123456789") != std::string::npos; j--);
				gearRatio *= std::stoi(matrix[i].substr(j, off - j));
				gearCount++;
			}
			// check right
			if (off + 1 < matrix[i].size() && matrix[i].substr(off + 1, 1).find_first_of("0123456789") != std::string::npos)
			{
				gearRatio *= std::stoi(matrix[i].substr(off + 1, matrix[i].find_first_not_of("0123456789", off + 1) - off));
				gearCount++;
			}
			// check top
			size_t start = off;
			if (start)
			{
				start--;
			}
			if (i && matrix[i - 1].substr(start, 3).find_first_of("0123456789") != std::string::npos)
			{
				int j = matrix[i - 1].find_first_of("0123456789", start);
				for (; j > 0 && matrix[i - 1].substr(j - 1, 1).find_first_of("0123456789") != std::string::npos; j--);
				size_t end = matrix[i - 1].find_first_not_of("0123456789", j);
				gearRatio *= std::stoi(matrix[i - 1].substr(j, end - j));
				gearCount++;
				// check other adjacent
				if (off + 1 < matrix[i - 1].size() && end == off && matrix[i - 1].substr(off + 1, 1).find_first_of("0123456789") != std::string::npos)
				{
					gearRatio *= std::stoi(matrix[i - 1].substr(off + 1, matrix[i - 1].find_first_not_of("0123456789", off + 1) - (off + 1)));
					gearCount++;
				}
			}
			// check bottom
			if (i + 1 < matrix.size() && matrix[i + 1].substr(start, 3).find_first_of("0123456789") != std::string::npos)
			{
				int j = matrix[i + 1].find_first_of("0123456789", start);
				for (; j > 0 && matrix[i + 1].substr(j - 1, 1).find_first_of("0123456789") != std::string::npos; j--);
				size_t end = matrix[i + 1].find_first_not_of("0123456789", j);
				gearRatio *= std::stoi(matrix[i + 1].substr(j, end - j));
				gearCount++;
				// check other adjacent
				if (off + 1 < matrix[i + 1].size() && end == off && matrix[i + 1].substr(off + 1, 1).find_first_of("0123456789") != std::string::npos)
				{
					gearRatio *= std::stoi(matrix[i + 1].substr(off + 1, matrix[i + 1].find_first_not_of("0123456789", off + 1) - (off + 1)));
					gearCount++;
				}
			}
			if (gearCount == 2)
			{
				count += gearRatio;
			}
		}
	}

	std::cout << "Day3 Part2: " << count << "\n";
}
