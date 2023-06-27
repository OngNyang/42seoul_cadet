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
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << this->name << " ScavTrap is constructed." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << this->name << " ScavTrap is destructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << name << " ScavTrap is copy-constructed." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
	}
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << obj.name << " ScavTrap is copy-assigned." << std::endl;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "there's no point left." << std::endl;
		return ;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " is now on Gate keeper mode." << std::endl;
	}
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "there's no point left." << std::endl;
		return ;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
}
