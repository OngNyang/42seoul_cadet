#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	a("alpha");
	ClapTrap	b("beta");

	std::cout << std::endl;
	a.attack("beta");
	b.takeDamage(a.getter_dmg());
	std::cout << std::endl;
	a.setter_dmg(6);
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