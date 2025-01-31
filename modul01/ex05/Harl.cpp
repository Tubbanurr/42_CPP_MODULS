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
    typedef void (Harl::*HarlMemFn)(void);
    HarlMemFn functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*functions[i])();
            break;
        }
    }
}
