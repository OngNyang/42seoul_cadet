#include "Animal.hpp"

//Animal class implement
Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << this->type << " Animal class is constructed by default." << std::endl;
}

Animal::Animal(const Animal& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Animal class is copy-constructed." << std::endl;
	}
}

Animal&	Animal::operator=(const Animal& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Animal class is copy-assigned." << std::endl;
		return (*this);
	}
}

Animal::~Animal(void)
{
	std::cout << this->type << " Animal class is destructed." << std::endl;
}