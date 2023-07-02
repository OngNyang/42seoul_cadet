#include "WrongCat.hpp"

//WrongCat class implement
WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << this->type << " WrongCat class is constructed by default." << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " WrongCat class is copy-constructed." << std::endl;
	}
}

WrongCat&	WrongCat::operator=(const WrongCat& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " WrongCat class is copy-assigned." << std::endl;
		return (*this);
	}
}

WrongCat::~WrongCat(void)
{
	std::cout << this->type << " WrongCat class is destructed." << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meow~" << std::endl;
}