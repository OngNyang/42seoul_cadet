#include "Zombie.hpp"

Zombie::Zombie(void)
{
	name = "default";
}

Zombie::Zombie(std::string str)
{
	name = str;
}

Zombie::~Zombie()
{
	std::cout << name << " is destryed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": ";
	std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}