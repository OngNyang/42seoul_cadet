#include "Character.hpp"

Character::Character(void)
{
	this->name = "default";
	for (int i=0; i<4; i++)
		slot[i] = nullptr;
	std::cout << "Character class is constructed." << std::endl;
}

Character::Character(const Character& obj)
{
	if (this == &obj)
	{
		std::cout << "copy-constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->name = obj.name;
		for (int i=0; i<4; i++)
			this->slot[i] = obj.slot[i];
		std::cout  << " Character class is copy-constructed." << std::endl;
	}
}

Character::~Character(void)
{
	std::cout << "Character is destructed." << std::endl;
}

Character&	Character::operator=(const Character& obj)
{
	if (this == &obj)
	{
		std::cout << "copy-assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->name = obj.name;
		for (int i=0; i<4; i++)
			this->slot[i] = obj.slot[i];
		std::cout << " Character class is copy-assigned." << std::endl;
		return (*this);
	}
}

std::string const& Character::getName()
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	bool	flag = false;

	for (int i=0; i<4; i++)
	{
		if (slot[i] == nullptr)
		{
			slot[i] = m;
			flag = true;
			std::cout << "equipment success." << std::endl;
		}
	}
	if (flag == false)
		std::cout << "slot is full." << std::endl;
}

void	Character::unequip(int idx)
{
	if (slot[idx] == nullptr)
	{
		std::cout << "invalid idx for unequipment. : " << idx << std::endl;
		return ;
	}
	else
	{
		slot[idx] = nullptr;
		std::cout << "unequipment succes." << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (slot[idx] == nullptr)
	{
		std::cout << "invalid idx for using. : " << idx << std::endl;
		return ;
	}
	AMateria::use(target)
}