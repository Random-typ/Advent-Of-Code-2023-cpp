#include "adventOfCode.h"

void day7() {
	std::fstream fs("input/day7.txt");
	checkFile;

	const char* cardTypes = "23456789TJQKA";
	auto getCardValue = [&cardTypes](char _card) -> int {
		for (int i = strlen(cardTypes) - 1; i >= 0; i--)
		{
			if (_card == cardTypes[i])
			{
				return i;
			}
		}
		return 0xff;
		};

	
	std::vector<std::tuple<std::string, size_t, size_t, char>> hands;
	for (std::string line; std::getline(fs, line); ) {
		size_t off = line.find(' ');
		
		std::string hand = line.substr(0, off);
		
		int highest = 0;
		char highestType = '2';
		for (size_t i = 0; i < hand.size(); i++)
		{
			int count = 0;
			for (size_t j = 0; j < hand.size(); j++)
			{
				if (hand[i] == hand[j])
				{
					count++;
				}
			}
			if (count > highest)
			{
				highestType = hand[i];
				highest = count;
				continue;
			}
			if (count == highest && getCardValue(highestType) < getCardValue(hand[i]))
			{
				highestType = hand[i];
				highest = count;
			}
		}
		
		hands.emplace_back(hand, std::stoull(line.substr(off + 1)), highest, highestType);
	}
	// sort
	std::sort(hands.begin(), hands.end(), [&getCardValue](const std::tuple<std::string, size_t, size_t, char>& a, const std::tuple<std::string, size_t, size_t, char>& b) -> bool {
		if (std::get<2>(a) != std::get<2>(b))
		{
			return std::get<2>(a) > std::get<2>(b);
		}
		if (std::get<3>(a) != std::get<3>(b))
		{// compare high card type
			return getCardValue(std::get<3>(a)) > getCardValue(std::get<3>(b));
		}
		// compare cards
		for (size_t i = 0; i < std::get<0>(a).size(); i++)
		{
			if (getCardValue(std::get<0>(a)[i]) == getCardValue(std::get<0>(b)[i]))
			{
				continue;
			}
			return getCardValue(std::get<0>(a)[i]) > getCardValue(std::get<0>(b)[i]);
		}
		// same value
		return false;
		});
	// calculate final sum
	size_t finalSum = 0;
	for (int i = hands.size() - 1; i >= 0; i--)
	{
		finalSum += std::get<1>(hands[i]) * (hands.size() - i);
	}

	std::cout << "Day7: " << finalSum << "\n";// should be 250957639
}