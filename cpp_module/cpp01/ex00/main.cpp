#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie = newZombie("heap zombie");
	heap_zombie->announce();
	delete heap_zombie;
	randomChump("stack zombie");
}