#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	slot = new AMateria*[4];
	for (int i=0; i < 4; i++)
	{
		slot[i] = nullptr;
	}
	std::cout << "default constructor of MateriaSource class is called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	slot = new AMateria*[4];
	for (int i=0; i<4; i++)
	{
		slot[i] = obj.slot[i]->clone();
	}
	std::cout << "copy constructor of MateriaSource class is called." << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &obj)
{
	for (int i=0; i<4; i++)
	{
		if (slot[i] != nullptr)
			delete slot[i];
		slot[i] = obj.slot[i]->clone();
	}
	return (*this);
}

