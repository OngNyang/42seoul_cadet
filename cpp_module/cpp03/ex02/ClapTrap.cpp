#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->name = "unknown";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << name << " ClapTrap is constructed." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << name << " ClapTrap is constructed." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->name << " ClapTrap is destructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << name << " ClapTrap is copy-constructed." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
	}
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << obj.name << " ClapTrap is copy-assigned." << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "there's no point left." << std::endl;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
		this->energy_points--;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0 || this->hit_points == 0)
	{
		std::cout << "there's no point left." << std::endl;
		return ;
	}
	else
	{
		this->energy_points--;
		this->hit_points = this->hit_points + amount;
		std::cout << "ClapTrap " << this->name << " repairs itself. Now it has " << this->hit_points << "hit points" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << "Please do not hurt dead ClapTrap." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damages. ";
	this->hit_points -= amount;
	if (this->hit_points <= 0)
	{
		this->hit_points = 0;
		std::cout << "ClapTrap " << this->name << " died." << std::endl;
	}
	else
	{
		std::cout << this->hit_points << " hit points left." << std::endl;
	}
}

int	ClapTrap::getter_dmg(void)
{
	std::cout << "ClapTrap " << this->name << "'s attack damage is given" << std::endl;
	return (this->attack_damage);
}

void	ClapTrap::setter_dmg(int dmg)
{
	this->attack_damage = dmg;
	std::cout << "ClapTrap " << this->name << "'s attack damage is set as " << dmg << "." << std::endl;
}
