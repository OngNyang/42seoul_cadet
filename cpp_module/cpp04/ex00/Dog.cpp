#include "Dog.hpp"

//Dog class implement
Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << this->type << " Dog class is constructed by default." << std::endl;
}

Dog::Dog(const Dog& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Dog class is copy-constructed." << std::endl;
	}
}

Dog&	Dog::operator=(const Dog& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Dog class is copy-assigned." << std::endl;
		return (*this);
	}
}

Dog::~Dog(void)
{
	std::cout << this->type << " Dog class is destructed." << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "Bark!" << std::endl;
}
