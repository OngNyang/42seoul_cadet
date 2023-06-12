#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	a("alpha");
	ScavTrap	b("beta");

	std::cout << std::endl;
	a.attack("beta");
	b.takeDamage(a.getter_dmg());
	std::cout << std::endl;
	a.setter_dmg(60);
	std::cout << std::endl;
	a.attack("beta");
	b.takeDamage(a.getter_dmg());
	std::cout << std::endl;
	a.attack("beta");
	b.takeDamage(a.getter_dmg());
	std::cout << std::endl;
	a.attack("beta");
	b.takeDamage(a.getter_dmg());
	std::cout << std::endl;
}