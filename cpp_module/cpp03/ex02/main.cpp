#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap	a("alpha");
	ScavTrap	b("beta");
	// FragTrap	c(b);
	FragTrap	c(a);

	std::cout << std::endl;

	a.highFivesGuys();
	// b.highFivesGuys();

	std::cout << std::endl;

	a.attack("beta");
	b.attack("alpha");

	FragTrap	*ft = new FragTrap("ft");
	delete ft;
	std::cout << std::endl;

	ClapTrap	*ct = new FragTrap("ct");
	delete ct;
	std::cout << std::endl;
}