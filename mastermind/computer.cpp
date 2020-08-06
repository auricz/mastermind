#include <vector>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include "computer.h"
#include <iostream>

const std::vector<char> Computer::possible_nums = { '1', '2', '3', '4', '5', '6' };

std::vector<char> Computer::sort(std::vector<char> feedback)
{
	std::vector<char> sorted_vec;
	for (int i = 0; i < 4; i++)
	{
		if (feedback[i] == '+')
		{
			sorted_vec.push_back('+');
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (feedback[i] == '-')
		{
			sorted_vec.push_back('-');
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (feedback[i] == ' ')
		{
			sorted_vec.push_back(' ');
		}
	}
	return sorted_vec;
}

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

std::vector<char> Computer::give_feedback(std::vector<char> current_guess, std::vector<char> solution)
{
	std::vector<char> current_feedback;
	std::vector<char> temp_guess = current_guess;
	std::vector<char> temp_solution = solution;
	for (int i = 0; i < 4; i++)
	{
		if (temp_guess[i] == temp_solution[i])
		{
			current_feedback.push_back('+');
			temp_guess[i] = '-';
			temp_solution[i] = '=';
		}
	}
	for (int i = 0; i < 4; i++)
	{
		if (std::find(temp_solution.begin(), temp_solution.end(), temp_guess[i]) != temp_solution.end())
		{
			current_feedback.push_back('-');
			temp_guess[i] = '-';
			temp_solution[i] = '=';
		}
		else
		{
			current_feedback.push_back(' ');
		}
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << solution[i];
	}
	return sort(current_feedback);
}
