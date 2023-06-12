#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	protected:
			std::string name;
			int			hit_points;
			int			energy_points;
			int			attack_damage;
	public:
			ClapTrap(void);
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& obj);
			virtual ~ClapTrap(void);
			ClapTrap&	operator=(const ClapTrap& obj);
			virtual void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
			int		getter_dmg(void);
			void	setter_dmg(int dmg);
};

#endif