#include <iostream>
#include "player.h"

bool Player::is_input_valid(std::string s)
{
    if (s.length() == 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (s[i] != 'R' && s[i] != 'O' && s[i] != 'Y' && s[i] != 'G' && s[i] != 'B' && s[i] != 'P')
            {
                std::cout << "\nOnly enter letters of ROYGBP.\n\n";
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
        std::cout << "\nEnter 4 letters only.\n\n";
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
