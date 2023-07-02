#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
#include <string>

class	Dog :public Animal
{
	private:
			Brain	*brain;
	public:
			Dog(void);
			Dog(const Dog& obj);
			Dog&	operator=(const Dog& obj);
			~Dog(void);
			void	makeSound(void) const;
			std::string	getBrain(int idx);
			void	setBrain(std::string str, int idx);
			// std::string	getType(void);
};

#endif