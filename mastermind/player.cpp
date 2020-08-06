#include <iostream>
#include "player.h"

bool Player::is_input_valid(std::string s)
{
    if (s.length() == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6')
            {
                std::cout << "\nOnly enter numbers from 1 to 6.\n\n";
                return false;
            }
        }
        return true;
    }
    else if (s.empty())
    {
        return false;
    }
    else
    {
        std::cout << "\nEnter 4 numbers only.\n\n";
        return false;
    }
}

std::string Player::ask_player()
{
    std::string input;
    bool is_valid_input = false;
    while (!is_input_valid(input))
    {
        std::cout << "Enter your guess: ";
        std::cin >> input;
    }
    return input;
}
