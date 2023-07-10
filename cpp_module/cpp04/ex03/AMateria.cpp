#include "AMateria.hpp"

AMateria::AMateria(void)
{
	this->type = "default";
	std::cout << "AMateria is constructed by default." << std::endl;
}

AMateria::AMateria(const AMateria& obj)
{
	if (this == &obj)
	{
		std::cout << "copy-constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << "AMateria is copy-constructed." << std::endl;
	}
}

AMateria&	AMateria::operator=(const AMateria& obj)
{
	if (this == &obj)
	{
		std::cout << "copy-assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << "AMateria is copy-assigned." << std::endl;
		return (*this);
	}
}

AMateria::~AMateria(void)
{
	std::cout  << "AMateria is destructed." << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << "AMateria is constructed." << std::endl;
}

std::string	const & AMateria::getType() const
{
	return (this->type);
}

// void	AMateria::use(ICharacter& target)
// {

// }