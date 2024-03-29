#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

#endif
class	PhoneBook
{
	public:
			PhoneBook();
			~PhoneBook();
			void	set_contact(int i, std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
			std::string	getter_fn(int i) const;
			std::string	getter_ln(int i) const;
			std::string	getter_nn(int i) const;
			std::string	getter_pn(int i) const;
			std::string	getter_ds(int i) const;
	private:
			Contact m_arr_contact[8];
};

#endif