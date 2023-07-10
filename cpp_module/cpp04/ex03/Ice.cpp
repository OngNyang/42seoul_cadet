#include "Ice.hpp"

Ice::Ice(void)
{
	this->type = "ice";
	std::cout << this->type << " Ice class is constructed." << std::endl;
}

Ice::Ice(const Ice& obj)
{
	if (this == &obj)
	{
		std::cout << "copy-constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Ice class is copy-constructed." << std::endl;
	}
}

Ice::~Ice(void)
{
	std::cout << this->type << " Ice class is destructed." << std::endl;
}

Ice&	Ice::operator=(const Ice& obj)
{
	if (this == &obj)
	{
		std::cout << "copy-assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Ice class is copy-assigned." << std::endl;
		return (*this);
	}
}

AMateria*	Ice::clone() const
{
	AMateria*	temp = new Ice(*this);
	return (temp);
}
