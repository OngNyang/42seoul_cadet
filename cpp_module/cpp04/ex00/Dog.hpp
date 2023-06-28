#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog :public Animal
{
	public:
			Dog(void);
			Dog(const Dog& obj);
			Dog&	operator=(const Dog& obj);
			~Dog(void);
			void	makeSound(void);
};

#endif