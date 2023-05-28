#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{

}

HumanB::~HumanB()
{

}

void	HumanB::attack(void)
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
