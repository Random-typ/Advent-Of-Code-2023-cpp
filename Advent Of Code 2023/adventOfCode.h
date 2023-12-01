#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <functional>

#define checkFile \
if (!fs.is_open()) { \
	std::cout << "Failed to open file!\n"; \
	return;\
}

void day1();
void day1Part2();



