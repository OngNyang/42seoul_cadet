#include "Weapon.hpp"

Weapon::Weapon(std::string str)
{
	type = str;
}

Weapon::Weapon(void)
{

}

Weapon::~Weapon()
{

}

const std::string&	Weapon::getType(void)
{
	const std::string&	ref = this->type;

	return (ref);
}

void	Weapon::setType(std::string str)
{
	this->type = str;
}