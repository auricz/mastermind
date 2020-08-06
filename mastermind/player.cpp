#include <iostream>
#include "player.h"

std::string Player::ask_player()
{
    std::string input;
    bool is_valid_input = false;
    while (!is_valid_input)
    {
        std::cout << "Enter your guess: ";
        std::cin >> input;
    }
    return input;
}
