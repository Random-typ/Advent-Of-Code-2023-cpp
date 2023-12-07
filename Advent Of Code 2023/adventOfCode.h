#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <functional>
#include <thread>
//#include <future>

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
void day5Part2();

void day6();
void day6Part2();

void day7();