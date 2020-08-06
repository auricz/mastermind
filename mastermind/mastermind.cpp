/* 
Mastermind is a game where player will guess a code in the form of colors (red, orange, yellow, green, blue, purple).
The computer will make a code randomly at the start and the player will guess the code.
After each guess, the computer will give feedback on the guess (if a color is correct but in right or wrong spot).
Player wins if he/she guesses the code in 10 guesses or less.
*/

#include <iostream>
#include "game.h"

int main()
{
    Game::show_intro();
    
    Game game;
    
    while (!game.is_player_winner() && !game.reached_max_guesses())
    {
        game.player_guess();
        game.show_board();
    }

    if (game.is_player_winner())
    {
        std::cout << "\nCongratulations, you guessed the correct code: " << game.get_solution() << "\n";
    }
    else if (game.reached_max_guesses())
    {
        std::cout << "\nYou lost. The correct code was " << game.get_solution() << "\n";
    }
}
