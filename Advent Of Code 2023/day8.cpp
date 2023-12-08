#include "adventOfCode.h"

enum class Flags {
	None,
	Start,
	End
};

void day8() {
	std::fstream fs("input/day8.txt");
	checkFile;

	std::vector<std::tuple<std::string, std::string, std::string>> nodes;
	std::string instructions;
	for (std::string line; std::getline(fs, line); )
	{
		if (instructions.empty())
		{
			instructions = line;
			continue;
		}
		if (line.empty())
		{
			continue;
		}
		
		nodes.emplace_back(line.substr(0, 3), line.substr(7, 3), line.substr(12, 3));
	}

	std::vector<std::tuple<size_t, size_t, size_t, Flags>> indexedMap;
	indexedMap.resize(nodes.size());
	size_t location = 0;

	for (size_t i = 0; i < nodes.size(); i++)
	{
		size_t leftNodeIndex = 0;
		size_t rightNodeIndex = 0;
		for (size_t j = 0; j < nodes.size(); j++)
		{
			if (std::get<0>(nodes[j]) == std::get<1>(nodes[i]))
			{
				leftNodeIndex = j;
				if (rightNodeIndex)
				{
					break;
				}
			}
			if (std::get<0>(nodes[j]) == std::get<2>(nodes[i]))
			{
				rightNodeIndex = j;
				if (leftNodeIndex)
				{
					break;
				}
			}
		}

		indexedMap[i] = { i, leftNodeIndex, rightNodeIndex, std::get<0>(nodes[i]) == "AAA" ? Flags::Start : std::get<0>(nodes[i]) == "ZZZ" ? Flags::End : Flags::None };
		if (std::get<3>(indexedMap[i]) == Flags::Start)
		{// start
			location = i;
		}
	}
	// find da way
	size_t steps = 0;

	for (size_t i = 0; i < instructions.size(); ++i == instructions.size() ? i = 0 : i)
	{
		if (std::get<3>(indexedMap[location]) == Flags::End)
		{// end
			break;
		}
		steps++;
		if (instructions[i] == 'L')
		{// left
			location = std::get<1>(indexedMap[location]);
			continue;
		}
		location = std::get<2>(indexedMap[location]);
	}

	std::cout << "Day8:" << steps << "\n";
}

void day8Part2() {
	std::fstream fs("input/day8.txt");
	checkFile;

	std::vector<std::tuple<std::string, std::string, std::string>> nodes;
	std::string instructions;
	for (std::string line; std::getline(fs, line); )
	{
		if (instructions.empty())
		{
			instructions = line;
			continue;
		}
		if (line.empty())
		{
			continue;
		}

		nodes.emplace_back(line.substr(0, 3), line.substr(7, 3), line.substr(12, 3));
	}

	std::vector<std::tuple<size_t, size_t, size_t, Flags>> indexedMap;
	indexedMap.resize(nodes.size());
	std::vector<size_t> locations;

	for (size_t i = 0; i < nodes.size(); i++)
	{
		size_t leftNodeIndex = 0;
		size_t rightNodeIndex = 0;
		for (size_t j = 0; j < nodes.size(); j++)
		{
			if (std::get<0>(nodes[j]) == std::get<1>(nodes[i]))
			{
				leftNodeIndex = j;
				if (rightNodeIndex)
				{
					break;
				}
			}
			if (std::get<0>(nodes[j]) == std::get<2>(nodes[i]))
			{
				rightNodeIndex = j;
				if (leftNodeIndex)
				{
					break;
				}
			}
		}
		
		indexedMap[i] = { i, leftNodeIndex, rightNodeIndex, std::get<0>(nodes[i]).ends_with('A') ? Flags::Start : std::get<0>(nodes[i]).ends_with('Z') ? Flags::End : Flags::None
		};
		if (std::get<3>(indexedMap[i]) == Flags::Start)
		{// start
			locations.emplace_back(i);
		}
	}
	auto allLocationsEnd = [&locations, &indexedMap]() -> bool {
		for (const auto& location : locations)
		{
			if (std::get<3>(indexedMap[location]) != Flags::End)
			{
				return false;
			}
		}
		// end
		return true;
		};

	// find da way
	// profiler
	size_t steps = 0;
	bool runProfiler = true;
	auto profiler = [&steps, &runProfiler]() {
		for (size_t i = 1;runProfiler;i++)
		{
			std::cout << "steps: " << steps << " " << steps / i << "/s\r";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		};

	// run profiler
	std::future<void> profilerTh = std::async(std::launch::async, profiler);
	
	for (size_t instructionIndex = 0; instructionIndex < instructions.size(); ++instructionIndex == instructions.size() ? instructionIndex = 0 : instructionIndex)
	{
		if (allLocationsEnd())
		{
			break;
		}
		steps++;
		for (auto& location : locations)
		{
			if (instructions[instructionIndex] == 'L')
			{// left
				location = std::get<1>(indexedMap[location]);
				continue;
			}
			location = std::get<2>(indexedMap[location]);
		}
	}
	runProfiler = false;
	profilerTh.wait();
	std::cout << "\n";

	std::cout << "Day8 Part2:" << steps << "\n";
}
