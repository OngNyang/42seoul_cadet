#include "main.hpp"

// bool	is_space(char c)
// {
// 	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
// 		return (true);
// 	else
// 		return (false);
// }

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

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;
	int			i = 0;

	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit(1);
		if (cmd == "EXIT")
		{
			return (0);
		}
		else if (cmd == "ADD")
		{
			//새 연락처 한번에 하나씩 프롬프팅
			//전부 받으면 폰북 클래스에 넣기
			//first name, last name, nickname, phone number, darkest secret.
			//빈 필드가 있을수 없다.(공백 문자는 부적절 문자로 거절한다.)
			std::string	first_name = get_info("first name : ");
			std::string	last_name = get_info("last name : ");
			std::string	nickname = get_info("nickname : ");
			std::string	phone_number = get_info("phone_number : ");
			std::string	darkest_secret = get_info("darkest_secret : ");
			phonebook.set_contact(i++, first_name, last_name, nickname, phone_number, darkest_secret);
		}
		else if (cmd == "SEARCH")
		{
			// index---first name---last name---nick name
			//10글자. 초과한다면, 9글자 + '.'
			// '|'로 구분짓기
			//인덱스 다시 묻기. 
			//	인덱스가 잘못되면 에러 핸들링
			//	제대로 됬다면, 정보를 한줄에 하나씩.

			std::cout << "index     " << " | ";
			std::cout << "first name" << " | ";
			std::cout << "last name " << " | ";
			std::cout << "nick name " << std::endl;
			for (int i=0; i<8; i++)
			{
				std::cout << i << "         " << " | ";
				print_ten(phonebook.getter_fn(i));
				std::cout << " | ";
				print_ten(phonebook.getter_ln(i));
				std::cout << " | ";
				print_ten(phonebook.getter_nn(i));
				std::cout << std::endl;

				// std::cout << phonebook.getter_fn(i) << "|";
				// std::cout << phonebook.getter_ln(i) << "|";
				// std::cout << phonebook.getter_nn(i) << std::endl;
			}
		}
		else
		{
			std::cout << "help: only ADD, EXIT and SEARCH is accepted." << std::endl;
		}
	}
}