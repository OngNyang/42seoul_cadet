#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class	Brain
{
	private:
			std::string	ideas[100];
	public:
			Brain(void);
			Brain(const Brain& obj);
			Brain&	operator=(const Brain& obj);
			~Brain(void);
			std::string	getIdeas(int idx);
			void		setIdeas(std::string str, int idx);
};

#endif