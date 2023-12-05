#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <functional>

#define checkFile \
if (!fs.is_open()) { \
	std::cout << "Failed to open file!\n"; \
	return;\
}

void day1();
void day1Part2();

void day2();
void day2Part2();

void day3();
void day3Part2();

void day4();
void day4Part2();

void day5();