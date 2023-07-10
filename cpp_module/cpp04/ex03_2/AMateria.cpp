#include "AMateria.hpp"

AMateria::AMateria(void)
{
	this->type = "default";
	std::cout << "default constructor of AMateria class is called." << std::endl;
}

AMateria::AMateria(std::string const & src)
{
	this->type = src;
	std::cout << "string constructor of AMateria class is called." << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "destructor of AMateria class is called." << std::endl;
}

std::string	const & AMateria::getType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter & target)
{
	/* data */
	std::cout << "uss function of AMateria class." << std::endl;
}
