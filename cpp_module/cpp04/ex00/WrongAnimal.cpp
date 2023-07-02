#include "WrongAnimal.hpp"

//Animal class implement
WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";
	std::cout << this->type << " WrongAnimal class is constructed by default." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " WrongAnimal class is copy-constructed." << std::endl;
	}
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " WrongAnimal class is copy-assigned." << std::endl;
		return (*this);
	}
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << this->type << " WrongAnimal class is destructed." << std::endl;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Hm Hmm..." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}