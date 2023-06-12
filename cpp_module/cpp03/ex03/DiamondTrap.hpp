#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
			std::string name;
	public:
			DiamondTrap(void);
			DiamondTrap(std::string name);
			~DiamondTrap(void);
			DiamondTrap(const DiamondTrap& obj);
			DiamondTrap&	operator=(const DiamondTrap& obj);
			void	attack(const std::string& target);
			void	whoAmi(void);
};


#endif