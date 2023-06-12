#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->name = "unknown";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << this->name << " FragTrap is constructed." << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << this->name << " FragTrap is constructed." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << this->name << " FragTrap is destructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << name << " FragTrap is copy-constructed." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
	}
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << obj.name << " FragTrap is copy-assigned." << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants to high fives." << std::endl;
}