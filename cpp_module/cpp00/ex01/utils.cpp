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
		std::cout << std::setw(10) << std::right << (str.substr(0, 9) + ".");
	}
	else
	{
		std::cout << std::setw(10) << std::right << str;
	}
}

int	string_to_int(const std::string& str)
{
	if (str.length() != 1)
		return (-1);
	else
	{
		if (!('0' <= str[0] && str[0] <= '7'))
			return (-1);
		else
			return (str[0] - '0');
	}
}
