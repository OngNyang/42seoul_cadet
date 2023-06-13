#include <iostream>

class	Animal
{
	protected:
			std::string	type;
	public:
			Animal(void);
			Animal(const Animal& obj);
			Animal&	operator=(const Animal& obj);
			virtual ~Animal(void);
};

class	Cat : public Animal
{
	public:
			Cat(void);
			Cat(const Cat& obj);
			Cat&	operator=(const Cat& obj);
			~Cat(void);
			void	makeSound(void);
};

class	Dog :public Animal
{
	public:
			Dog(void);
			Dog(const Dog& obj);
			Dog&	operator=(const Dog& obj);
			~Dog(void);
			void	makeSound(void);
};

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << this->type << " Animal class is constructed by default." << std::endl;
}

Animal::Animal(const Animal& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Animal class is copy-constructed." << std::endl;
	}
}

Animal&	Animal::operator=(const Animal& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << "Copy assignment "
		return (*this);
	}
}

Animal::~Animal(void)
{

}



int	main(void)
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	return (0);
}