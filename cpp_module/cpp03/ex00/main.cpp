#include <iostream>

class	ClapTrap
{
	private:
			std::string name;
			int			hit_points;
			int			energy_points;
			int			attack_damage;
	public:
			ClapTrap(void);
			ClapTrap(std::string name);
			ClapTrap(const ClapTrap& obj);
			~ClapTrap(void);
			ClapTrap&	operator=(const ClapTrap& obj);
			void	attack(const std::string& target);
			void	takeDamage(unsigned int amount);
			void	beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap(void)
{
	this->name = "unknown";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << name << " ClapTrap is constructed." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << name << " ClapTrap is constructed." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << this->name << " ClapTrap is destructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	this->name = obj.name;
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << name << " ClapTrap is copy-constructed." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
	}
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << obj.name << " ClapTrap is copy-assigned." << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	
}


int main(void)
{
	ClapTrap	a("hj");
}