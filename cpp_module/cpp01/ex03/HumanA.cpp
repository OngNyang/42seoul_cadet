#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name),  weapon(weapon)
{

}

HumanA::~HumanA()
{

}

void	HumanA::attack(void)
{
	std::cout << this->name;
	std::cout << " attacks with their ";
	std::cout << weapon.getType() << std::endl;
}