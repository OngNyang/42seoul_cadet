#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
			AMateria*	slot[4];
			std::string	name;
	public:
			Character(void);
			Character(const Character& obj);
			~Character(void);
			Character&	operator=(const Character& obj);

			std::string const & getName();
			void	equip(AMateria* m);
			void	unequip(int idx);
			void	use(int idx, ICharacter& target);
};


#endif