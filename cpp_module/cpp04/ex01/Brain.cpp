#include "Brain.hpp"
#include <cstddef>

Brain::Brain(void)
{
	for (int i= 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "Brain class is constructed by default." << std::endl;
}

Brain::Brain(const Brain& obj)
{
	if (this == &obj)
	{
		std::cout << "copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		for (int i=0; i<100; i++)
			this->ideas[i] = obj.ideas[i];
		std::cout << "Brain class is copy-constructed." << std::endl;
	}
}

Brain&	Brain::operator=(const Brain& obj)
{
	if (this == &obj)
	{
		std::cout << "copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		for (int i=0; i<100; i++)
			this->ideas[i] = obj.ideas[i];
		std::cout << "Brain class is copy-assigned." << std::endl;
		return (*this);
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain class is destructed." << std::endl;
}

std::string	Brain::getIdeas(int idx)
{
	if (0 <= idx && idx <= 99)
	{
		std::cout << "no." << idx << " idea is given." << std::endl;
		return (this->ideas[idx]);
	}
	else
	{
		std::cout << "Invalid index" << std::endl;
		return ("");
	}
		// throw std::out_of_range("Invalid index");
}

void	Brain::setIdeas(std::string str, int idx)
{
	if (0 <= idx && idx <= 99)
	{
		this->ideas[idx] = str;
		std::cout << "no." << idx << " idea is set as ("<< str << ")." << std::endl;
	}
	else
		std::cout << "Invalid index" << std::endl;
		// throw std::out_of_range("Invalid index");
}