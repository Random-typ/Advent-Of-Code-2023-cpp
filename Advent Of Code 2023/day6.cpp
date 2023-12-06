#include "adventOfCode.h"

void day6() {
	std::fstream fs("input/day6.txt");
	checkFile;

	std::vector<int> times;
	std::vector<int> distances;
	for (std::string line; std::getline(fs, line); )
	{
		if (line.substr(0, line.find(':')) == "Time")
		{// Time
			size_t off = 6;/*"Time:"*/
			while (off != std::string::npos)
			{
				off = line.find_first_not_of(' ', off + 1);
				size_t end = line.find(' ', off + 1);
				times.emplace_back(std::stoi(line.substr(off, end - off)));
				off = end;
			}
			continue;
		}
		// Distance
		size_t off = 9; /*"Distance:"*/
		while (off != std::string::npos)
		{
			off = line.find_first_not_of(' ', off + 1);
			size_t end = line.find(' ', off);
			distances.emplace_back(std::stoi(line.substr(off, end - off)));
			off = end;
		}
	}

	int possibleWaysTotal = 1;
	for (size_t i = 0; i < times.size(); i++)
	{
		int possibleWays = 0;
		for (int holdTime = 1; holdTime < times[i]; holdTime++)
		{
			int distance = (times[i] - holdTime) * holdTime;
			if (distance > distances[i])
			{
				possibleWays++;
			}
		}
		possibleWaysTotal *= possibleWays;
	}

	std::cout << "Day6:" << possibleWaysTotal << "\n";
}

void day6Part2()
{
	std::fstream fs("input/day6.txt");
	checkFile;

	std::vector<size_t> times;
	std::vector<size_t> distances;
	for (std::string line; std::getline(fs, line); )
	{
		if (line.substr(0, line.find(':')) == "Time")
		{// Time
			size_t off = 6;/*"Time:"*/
			while (off != std::string::npos)
			{
				off = line.find_first_not_of(' ', off + 1);
				size_t end = line.find(' ', off + 1);
				times.emplace_back(std::stoull(line.substr(off, end - off)));
				off = end;
			}
			continue;
		}
		// Distance
		size_t off = 9; /*"Distance:"*/
		while (off != std::string::npos)
		{
			off = line.find_first_not_of(' ', off + 1);
			size_t end = line.find(' ', off);
			distances.emplace_back(std::stoull(line.substr(off, end - off)));
			off = end;
		}
	}
	// quick and dirty "conversion"
	std::string gluedTime;
	std::string gluedDistance;
	for (size_t i = 0; i < times.size(); i++)
	{
		gluedTime += std::to_string(times[i]);
		gluedDistance += std::to_string(distances[i]);
	}
	times = { std::stoull(gluedTime) };
	distances = { std::stoull(gluedDistance) };

	size_t possibleWaysTotal = 1;
	for (size_t i = 0; i < times.size(); i++)
	{
		size_t possibleWays = 0;
		for (size_t holdTime = 1; holdTime < times[i]; holdTime++)
		{
			size_t distance = (times[i] - holdTime) * holdTime;
			if (distance > distances[i])
			{
				possibleWays++;
			}
		}
		possibleWaysTotal *= possibleWays;
	}

	std::cout << "Day6 Part2:" << possibleWaysTotal << "\n";
}
