#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "default constructor of Ice class is called." << std::endl;
}

Ice::Ice(const Ice& obj) : AMateria(obj.getType())
{
	std::cout << "copy constructor of Ice class is called." << std::endl;
}

Ice&	Ice::operator=(const Ice& obj)
{
	this->type = obj.getType();
	std::cout << "copy assignment of Ice class is called." << std::endl;
}

Ice::~Ice(void)
{
	std::cout << "destructor of Ice class is called." << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria*	temp = new Ice();
	return (temp);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at bob *" << std::endl;
}