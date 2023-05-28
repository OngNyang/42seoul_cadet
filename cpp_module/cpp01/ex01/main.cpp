#include "Zombie.hpp"

int	main(void)
{
	int	N = 10;
	Zombie	*zombie_horde = zombieHorde(N, "hj");

	for (int i=0; i<N; i++)
	{
		zombie_horde[i].announce();
	}
	delete [] zombie_horde;
}