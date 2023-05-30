#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl(void)
{

}

Harl::~Harl(void)
{

}

void	Harl::complain(std::string level)
{
	void		(Harl::*function_ptr)(void) = nullptr;
	std::string	arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4)
	{
		if (arr[i] == level)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			function_ptr = &Harl::debug;
			break ;
		case 1:
			function_ptr = &Harl::info;
			break ;
		case 2:
			function_ptr = &Harl::warning;
			break ;
		case 3:
			function_ptr = &Harl::error;
			break ;
		default:
			std::cout << "Error: Invalid complaint" << std::endl;
			return ;
	}
	(this->*function_ptr)();
}