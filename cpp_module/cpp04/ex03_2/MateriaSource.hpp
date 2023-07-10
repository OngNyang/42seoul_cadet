#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
			AMateria	**slot;
	public:
			MateriaSource(void);
			MateriaSource(const MateriaSource& obj);
			MateriaSource&	operator=(const MateriaSource& obj);
			~MateriaSource(void);
			void	learnMateria(AMateria*);
			AMateria*	CreateMateria(std::string const &);
};

#endif