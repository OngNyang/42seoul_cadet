#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->name = "unknown";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << this->name << " ScavTrap is constructed." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << this->name << " ScavTrap is constructed." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->name << " ScavTrap is destructed." << std::endl;
}
