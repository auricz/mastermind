#pragma once
#include <string>

class Player
{
private:
	static bool is_input_valid(std::string the_input);
public:
	static std::string ask_player();
};