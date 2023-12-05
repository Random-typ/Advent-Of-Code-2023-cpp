#include "adventOfCode.h"




void day5()
{
	std::fstream fs("input/day5.txt");
	checkFile;

	std::vector<std::string> almanac;
	int count = 0;
	for (std::string line; std::getline(fs, line); )
	{
		almanac.emplace_back(line);
	}
	// parse seeds
	std::vector<size_t> seeds;
	for (size_t off = almanac[0].find(' '); off != std::string::npos; )
	{
		size_t end = almanac[0].find(' ', off + 1);
		if (end == std::string::npos)
		{
			seeds.emplace_back(std::stoull(almanac[0].substr(off, end)));
			break;
		}
		seeds.emplace_back(std::stoull(almanac[0].substr(off, end - off)));
		off = end;
	}

	// parse maps
	std::vector<std::vector<std::vector<size_t> /* rates */>/* conversions */> maps;
	// map 0 -> seed-to-soil 
	// map 1 -> soil-to-fertilizer
	// map 2 -> fertilizer-to-water
	// map 3 -> water-to-light
	// map 4 -> light-to-temperature
	// map 5 -> temperature-to-humidity
	// map 6 -> humidity-to-location
	
	std::vector<std::vector<size_t> /* rates */> map;
	for (size_t i = 1; i < almanac.size(); i++)
	{
		if (almanac[i].contains(':') && !map.empty())
		{
			maps.push_back(map);
			map.clear();
			continue;
		}
		if (almanac[i].empty() || almanac[i].contains(':'))
		{
			continue;
		}
		size_t start = 0;
		size_t end;
		map.emplace_back();
		for (size_t j = 0; j < 3; j++)
		{
			end = almanac[i].find(' ', start);
			map.back().emplace_back(std::stoull(almanac[i].substr(start, end - start)));
			start = end + 1;
		}
	}
	maps.push_back(map);
	// find seed locations
	std::vector<std::pair<size_t/*seed*/, size_t/*location*/>> seedLocations;

	for (auto& seed : seeds)
	{
		size_t value = seed;
		for (auto& map : maps)
		{
			for (auto& mapEntry : map)
			{
				if (value < mapEntry[1] || value > mapEntry[1] + mapEntry[2])
				{
					continue;
				}
				value = value - mapEntry[1] + mapEntry[0];
				break;
			}
		}
		seedLocations.emplace_back(seed, value);
	}

	// find lowest location
	size_t lowest = INT32_MAX;
	for (auto& i : seedLocations)
	{
		if (i.second < lowest)
		{
			lowest = i.second;
		}
	}

	std::cout << "Day5: " << lowest << "\n";
}


void day5Part2()
{
	std::fstream fs("input/day5.txt");
	checkFile;

	std::vector<std::string> almanac;
	int count = 0;
	for (std::string line; std::getline(fs, line); )
	{
		almanac.emplace_back(line);
	}
	// parse seeds
	std::vector<size_t> seeds;
	for (size_t off = almanac[0].find(' '); off != std::string::npos; )
	{
		size_t end = almanac[0].find(' ', off + 1);
		if (end == std::string::npos)
		{
			seeds.emplace_back(std::stoull(almanac[0].substr(off, end)));
			break;
		}
		seeds.emplace_back(std::stoull(almanac[0].substr(off, end - off)));
		off = end;
	}

	// parse maps
	std::vector<std::vector<std::vector<size_t> /* rates */>/* conversions */> maps;
	// map 0 -> seed-to-soil 
	// map 1 -> soil-to-fertilizer
	// map 2 -> fertilizer-to-water
	// map 3 -> water-to-light
	// map 4 -> light-to-temperature
	// map 5 -> temperature-to-humidity
	// map 6 -> humidity-to-location

	std::vector<std::vector<size_t> /* rates */> map;
	for (size_t i = 1; i < almanac.size(); i++)
	{
		if (almanac[i].contains(':') && !map.empty())
		{
			maps.push_back(map);
			map.clear();
			continue;
		}
		if (almanac[i].empty() || almanac[i].contains(':'))
		{
			continue;
		}
		size_t start = 0;
		size_t end;
		map.emplace_back();
		for (size_t j = 0; j < 3; j++)
		{
			end = almanac[i].find(' ', start);
			map.back().emplace_back(std::stoull(almanac[i].substr(start, end - start)));
			start = end + 1;
		}
	}
	maps.push_back(map);
	// find seed locations and find lowest

	size_t lowest = INT32_MAX;
	for (size_t i = 0; i < seeds.size(); i+=2)
	{
		std::cout << i << "\n";
		for (size_t seed = seeds[i]; seed < seeds[i] + seeds[i + 1]; seed++)// assumes an even number of seeds
		{
			size_t value = seed;
			for (auto& map : maps)
			{
				for (auto& mapEntry : map)
				{
					if (value < mapEntry[1] || value > mapEntry[1] + mapEntry[2])
					{
						continue;
					}
					value = value - mapEntry[1] + mapEntry[0];
					break;
				}
			}
			if (value < lowest)
			{
				lowest = value;
			}
		}
	}

	std::cout << "Day5 Part2: " << (lowest - 1/*odd*/) << "\n";
}