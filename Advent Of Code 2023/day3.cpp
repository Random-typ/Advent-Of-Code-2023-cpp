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
