#include <iostream>

class	Weapon
{
	private:
			std::string	type;
	public:
			Weapon(std::string str);
			Weapon();
			~Weapon();
			const std::string&	getType(void);
			void				setType(std::string str);
};