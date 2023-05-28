#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
			std::string	name;
	public:
			Zombie(void);
			~Zombie();
			void	announce(void);
			void	setter_name(std::string str);

};

Zombie*	zombieHorde(int N, std::string name);

#endif