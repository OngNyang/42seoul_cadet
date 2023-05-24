#include "main.hpp"

bool	all_white_space(std::string str)
{
	int	i = 0;

	while (1)
	{
		if (str[i] == '\0')
			return (true);
		if (isspace(str[i]) == 0)
			break;
		i++;
	}
	return (false);
}

std::string	get_info(std::string str)
{
	std::string	info;

	while (1)
	{
		std::cout << str;
		std::getline(std::cin, info);
		if (std::cin.eof())
			exit(1);
		if (all_white_space(info) == false)
			break ;
		else
			std::cout << "error: empty field" << std::endl;
	}
	return (info);
}

void	print_ten(std::string str)
{
	if (str.length() >= 10)
	{
		for (int i=0; i<9; i++)
		{
			std::cout << str[i];
		}
		std::cout << ".";
	}
	else
	{
		std::cout << str;
		for (unsigned long i=0; i<(10 - str.length()); i++)
			std::cout << " ";
	}
}

bool	check_choice(std::string str)
{
	int	choice = -1;

	if (str.length() == 1)
	{
		try
		{
			choice = std::stoi(str);
		}
		catch(const std::invalid_argument& e)
		{
			return (false);
		}
		if (0 <= choice && choice <= 7)
			return (true);
	}
	return (false);
}