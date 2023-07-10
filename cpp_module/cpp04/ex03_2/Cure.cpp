#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "default constructor of Cure is called." << std::endl;
}

Cure::Cure(const Cure& obj) : AMateria(obj.getType())
{
	std::cout << "copy constructor of Cure class is called." << std::endl;
}

Cure&	Cure::operator=(Cure const& obj)
{
	this->type = obj.getType();
	std::cout << "copy assignment of Cure class is called." << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "destructor of Cure class is called." << std::endl;
}

AMateria*	Cure::clone() const
{
	AMateria*	temp = new Cure();
	return (temp);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals bob's wounds *" << std::endl;
}