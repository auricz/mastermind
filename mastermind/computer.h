#pragma once
#include <vector>

class Computer
{
private:
	static const std::vector<char> possible_nums;
	static std::vector<char> sort(std::vector<char> feedback);
public:
	static std::vector<char> make_random_code();
	static std::vector<char> give_feedback(std::vector<char> current_guess, std::vector<char> solution);
};