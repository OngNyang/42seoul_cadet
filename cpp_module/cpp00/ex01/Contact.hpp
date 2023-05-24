#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact
{
	public:
			Contact();
			~Contact();
			void		setter(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
			std::string	getter_fn() const;
			std::string	getter_ln() const;
			std::string	getter_nn() const;
			std::string	getter_pn() const;
			std::string	getter_ds() const;
	private:
			std::string	m_first_name;
			std::string	m_last_name;
			std::string	m_nickname;
			std::string	m_phone_number;
			std::string	m_darkest_secret;
};

#endif