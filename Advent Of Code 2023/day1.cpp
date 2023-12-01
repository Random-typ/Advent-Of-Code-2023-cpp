#include "adventOfCode.h"

void day1() {
	std::fstream fs("input/day1.txt");
	checkFile;

	int count = 0;
	for (std::string str; std::getline(fs, str); )
	{
		count += std::stoi(std::string{ str[str.find_first_of("0123456789")], str[str.find_last_of("0123456789")] });
	}
	fs.close();

	std::cout << "Day1: " << count << "\n";
}

void day1Part2()
{
	
}
