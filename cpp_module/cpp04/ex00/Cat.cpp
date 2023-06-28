#include "Cat.hpp"

//Cat class implement
Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << this->type << " Cat class is constructed by default." << std::endl;
}

Cat::Cat(const Cat& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Cat class is copy-constructed." << std::endl;
	}
}

Cat&	Cat::operator=(const Cat& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Cat class is copy-assigned." << std::endl;
		return (*this);
	}
}

Cat::~Cat(void)
{
	std::cout << this->type << " Cat class is destructed." << std::endl;
}

void	Cat::makeSound(void)
{
	std::cout << "Meow~" << std::endl;
}
