#include "Zombie.hpp"

int	main(void)
{
	Zombie	*heap_zombie = newZombie("heap zombie");
	heap_zombie->announce();
	delete heap_zombie;
	Zombie	stack_zombie("stack zombie");
	stack_zombie.announce();
}