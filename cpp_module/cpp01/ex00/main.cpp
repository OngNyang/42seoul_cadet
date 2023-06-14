#include "Zombie.hpp"

// Zombie*	ret_zombie(void)
// {
// 	Zombie	zom("hj");

// 	return (&zom);
// }

int	main(void)
{
	Zombie	*heap_zombie = newZombie("heap zombie");
	heap_zombie->announce();
	delete heap_zombie;

	randomChump("stack zombie");

	// ret_zombie();
}