#include "Dog.hpp"

//Dog class implement
Dog::Dog(void)
{
	this->brain = new Brain();
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
		this->brain = new Brain(*(obj.brain));
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
		for (int i=0; i<100; i++)
		{
			try
			{
				this->brain->setIdeas(obj.brain->getIdeas(i), i);
			}
			catch (const std::out_of_range& e)
			{
				std::cout << "Invalid index:" << e.what() << std::endl;
			}
		}
		this->type = obj.type;
		std::cout << this->type << " Dog class is copy-assigned." << std::endl;
		return (*this);
	}
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << this->type << " Dog class is destructed." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark!" << std::endl;
}

std::string	Dog::getBrain(int idx)
{
	return (this->brain->getIdeas(idx));
}

void	Dog::setBrain(std::string str, int idx)
{
	this->brain->setIdeas(str, idx);
}


// std::string	Dog::getType(void)
// {
// 	return (this->type);
// }
