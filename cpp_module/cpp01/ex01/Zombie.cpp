#include "Zombie.hpp"

Zombie::Zombie(void)
{

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

void	Zombie::setter_name(std::string str)
{
	name = str;
}