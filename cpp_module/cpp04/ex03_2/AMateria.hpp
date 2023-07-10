#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class	AMateria
{
protected:
	std::string	type;
public:
	AMateria(void);
	AMateria(const AMateria& obj);
	virtual ~AMateria(void);
	AMateria&	operator=(const AMateria& obj);

	AMateria(std::string const & src);
	std::string	const &	getType() const; //returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter & target);
};


#endif