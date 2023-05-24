#include "main.hpp"

PhoneBook::PhoneBook()
{

}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::set_contact(int i, std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	m_arr_contact[i % 8].setter(fn, ln, nn, pn, ds);
}

std::string	PhoneBook::getter_fn(int i) const
{
	return (m_arr_contact[i].getter_fn());
}

std::string	PhoneBook::getter_ln(int i) const
{
	return (m_arr_contact[i].getter_ln());
}

std::string	PhoneBook::getter_nn(int i) const
{
	return (m_arr_contact[i].getter_nn());
}

std::string	PhoneBook::getter_pn(int i) const
{
	return (m_arr_contact[i].getter_pn());
}

std::string	PhoneBook::getter_ds(int i) const
{
	return (m_arr_contact[i].getter_ds());
}