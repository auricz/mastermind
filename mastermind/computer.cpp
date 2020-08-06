#include <vector>
#include <stdlib.h>
#include <ctime>
#include "computer.h"

const std::vector<char> Computer::possible_nums = { '1', '2', '3', '4', '5', '6' };

std::vector<char> Computer::make_random_code()
{
	srand((unsigned int)time(0));
	std::vector<char> code;
	for (int i = 0; i < 4; i++)
	{
		int rand_index = (rand() % 6);
		code.push_back(possible_nums[rand_index]);
	}
	return code;
}
