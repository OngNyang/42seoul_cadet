#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class	FragTrap : public virtual ClapTrap
{
	public:
			FragTrap(void);
			FragTrap(std::string name);
			FragTrap(const FragTrap& obj);
			~FragTrap(void);
			FragTrap&	operator=(const FragTrap& obj);
			void	highFivesGuys(void);
};


#endif