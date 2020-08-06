#include <iostream>
#include <string>
#include "game.h"
#include "player.h"
#include "computer.h"

const int Game::max_guesses = 10;

Game::Game()
{
	nums_of_guesses = 0;
	solution = Computer::make_random_code();
}

void Game::player_guess()
{
	current_guess = { ' ', ' ', ' ', ' ' };
	std::string inputed_guess = Player::ask_player();
	for (int i = 0; i < 4; i++)
	{
		current_guess[i] = inputed_guess[i];
	}
	std::vector<char> current_feedback = Computer::give_feedback(current_guess, solution);
	previous_guesses.push_back(current_guess);
	feedback.push_back(current_feedback);
	nums_of_guesses++;
}

void Game::show_board()
{
	std::cout << "\n";
	std::cout << "             Past Guesses  | Feedback \n";
	std::cout << "                           |          \n";
	for (unsigned int i = 0; i < previous_guesses.size(); i++)
	{
		std::vector<char> g = previous_guesses[i];
		std::vector<char> f = feedback[i];
		printf("   Guess %i	%c %c %c %c    | %c %c %c %c \n", i + 1, g[0], g[1], g[2], g[3], f[0], f[1], f[2], f[3]);
	}
}

bool Game::is_player_winner()
{
	if (current_guess == solution)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Game::reached_max_guesses()
{
	if (nums_of_guesses >= max_guesses)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string Game::get_solution()
{
	std::string str_solution = "----";
	for (int i = 0; i < 4; i++)
	{
		str_solution[i] = solution[i];
	}
	return str_solution;
}

void Game::show_intro()
{
	std::cout << "==============================\n";
	std::cout << "          Mastermind          \n";
	std::cout << "==============================\n";
	std::cout << "Guess a 4-digit code and try to guess the correct code. You must guess the correct code in 10 guesses or less to win.\n";
	std::cout << "After each guess, the computer will provide feedback next to your guess.\n";
	std::cout << "A - means a number in wrong spot, a + is a number in correct spot, and nothing means something is completely wrong.\n";
	std::cout << "You can choose numbers from 1 to 6, and enter your guess withou spaces (i.e. 1234).\n";
}

