#include "main.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::setter(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	m_first_name = fn;
	m_last_name = ln;
	m_nickname = nn;
	m_phone_number = pn;
	m_darkest_secret = ds;
}

std::string	Contact::getter_fn(void) const
{
	return (m_first_name);
}

std::string	Contact::getter_ln(void) const
{
	return (m_last_name);
}

std::string	Contact::getter_nn(void) const
{
	return (m_nickname);
}

std::string	Contact::getter_pn(void) const
{
	return (m_phone_number);
}

std::string	Contact::getter_ds(void) const
{
	return (m_darkest_secret);
}