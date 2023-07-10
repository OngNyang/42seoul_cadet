#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
	Cure(void);
	Cure(const Cure &obj);
	Cure&	operator=(const Cure &obj);
	~Cure(void);
	AMateria*	clone() const;
	void		use(ICharacter & target);
};

#endif