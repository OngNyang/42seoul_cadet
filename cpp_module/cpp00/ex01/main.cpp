#include "main.hpp"

void	print_simple_ver(PhoneBook *phonebook, int idx)
{
	if (idx >= 8)
		idx = 8;
	std::cout << "\033[32m";
	std::cout << "index     " << "|";
	std::cout << "first name" << "|";
	std::cout << "last name " << "|";
	std::cout << "nick name " << std::endl;
	for (int i=0; i < idx; i++)
	{
		std::cout << i << "         " << "|";
		print_ten((*phonebook).getter_fn(i));
		std::cout << "|";
		print_ten((*phonebook).getter_ln(i));
		std::cout << "|";
		print_ten((*phonebook).getter_nn(i));
		std::cout << std::endl;
	}
	std::cout << "choose index please." << std::endl;
	std::cout << "\033[0m";
}

void	print_specific_ver(PhoneBook *phonebook, std::string choice)
{
	int	choice_n = stoi(choice);
	
	std::cout << "\033[32m";
	std::cout << "first name     : ";
	std::cout << (*phonebook).getter_fn(choice_n) << std::endl;
	std::cout << "last name      : ";
	std::cout << (*phonebook).getter_ln(choice_n) << std::endl;
	std::cout << "nickname       : ";
	std::cout << (*phonebook).getter_nn(choice_n) << std::endl;
	std::cout << "phone number   : ";
	std::cout << (*phonebook).getter_pn(choice_n) << std::endl;
	std::cout << "darkest secret : ";
	std::cout << (*phonebook).getter_ds(choice_n) << std::endl;
	std::cout << "\033[0m";
}

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;
	int			i = 0;

	std::cout << "\033[32m";
	std::cout << " -----------" << std::endl;
	std::cout << "| PhoneBook |" << std::endl;
	std::cout << " -----------" << std::endl;
	std::cout << "available : ADD, SEARCH, EXIT" << std::endl;
	std::cout << "\033[0m";
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit(1);
		if (cmd == "EXIT")
		{
			std::cout << "\033[32m" <<"Good bye." << std::endl << "\033[0m";
			return (0);
		}
		else if (cmd == "ADD")
		{
			std::string	first_name = get_info("first name     : ");
			std::string	last_name = get_info("last name      : ");
			std::string	nickname = get_info("nickname       : ");
			std::string	phone_number = get_info("phone_number   : ");
			std::string	darkest_secret = get_info("darkest_secret : ");
			phonebook.set_contact(i++, first_name, last_name, nickname, phone_number, darkest_secret);
		}
		else if (cmd == "SEARCH")
		{
			print_simple_ver(&phonebook, i);
			std::cout << "> ";
			std::string	choice;
			std::getline(std::cin, choice);
			if (std::cin.eof())
				exit(1);
			if (check_choice(choice) == true)
				print_specific_ver(&phonebook, choice);
			else
				std::cout << "\033[32m" << "help: inappropriate choice" << std::endl << "\033[0m";
		}
		else
			std::cout << "\033[32m" << "help: only ADD, EXIT and SEARCH is accepted." << std::endl << "\033[0m";
	}
}