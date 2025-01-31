#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon on my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really love it!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I can't believe adding extra bacon costs more money. You didn't put enough bacon on my burger! If you did, I couldn't ask for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve some extra bacon for free. I've been coming for years, you started working here since last month." << std::endl;
}

void 	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to talk to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	switch (level[0])
	{
	case 'D':
		if (level == "DEBUG")
		{
			debug();
			complain("INFO");
		}
		else
			std::cout << "invalid input: [ Probably complaining about insignificant problems ]" << std::endl;
		break;
	case 'I':
		if (level == "INFO")
		{
			info();
			complain("WARNING");
		}
		else
			std::cout << "invalid input: [ Probably complaining about insignificant problems ]" << std::endl;
		break;
	case 'W':
		if (level == "WARNING")
		{
			warning();
			complain("ERROR");
		}
		else
			std::cout << "invalid input: [ Probably complaining about insignificant problems ]" << std::endl;
		break;
	case 'E':
		if (level == "ERROR")
			error();
		else
			std::cout << "invalid input: [ Probably complaining about insignificant problems ]" << std::endl;
		break;
	default:
		std::cout << "invalid input: [ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}
