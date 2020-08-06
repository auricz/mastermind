#pragma once
#include <vector>
#include <string>

class Game
{
private:
	int nums_of_guesses;
	std::vector<char> solution;
	std::vector<char> current_guess;
	std::vector<std::vector<char>> previous_guesses;
	std::vector<std::vector<char>> feedback;
	static const int max_guesses;
public:
	Game();
	void player_guess();			// Called to let player enter guess 
	void show_board();				// Shows the previous guesses and feedback
	bool is_player_winner();		// True if current guess is same as solution
	bool reached_max_guesses();		// True if 10 guesses have been made
	std::string get_solution();
	static void show_intro();		// Shows the intro at the start
};	