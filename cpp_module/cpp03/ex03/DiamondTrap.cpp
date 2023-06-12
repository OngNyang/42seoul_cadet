#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	ClapTrap::name += "_clap_name";
	ClapTrap::damage = 30;
	std::cout << "DiamondTrap_Name : " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string n)
{
	ClapTrap::name += "_clap_name";
	ClapTrap::attack_damage = 30;
}

// 포기
