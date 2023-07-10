#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class	Ice : public AMateria
{
	Ice(void);
	Ice(const Ice &obj);
	Ice&	operator=(const Ice &obj);
	~Ice(void);
	AMateria*	clone() const;
	void		use(ICharacter & target);
};

#endif