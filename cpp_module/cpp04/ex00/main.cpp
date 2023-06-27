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

//Animal class implement
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
		std::cout << this->type << " Animal class is copy-assigned." << std::endl;
		return (*this);
	}
}

Animal::~Animal(void)
{
	std::cout << this->type << " Animal class is destructed." << std::endl;
}

//Cat class implement
Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << this->type << " Cat class is constructed by default." << std::endl;
}

Cat::Cat(const Cat& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Cat class is copy-constructed." << std::endl;
	}
}

Cat&	Cat::operator=(const Cat& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Cat class is copy-assigned." << std::endl;
		return (*this);
	}
}

Cat::~Cat(void)
{
	std::cout << this->type << " Cat class is destructed." << std::endl;
}

void	Cat::makeSound(void)
{
	std::cout << "Meow~" << std::endl;
}

//Dog class implement
Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << this->type << " Dog class is constructed by default." << std::endl;
}

Dog::Dog(const Dog& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy constructor for itself. refused." << std::endl;
		return ;
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Dog class is copy-constructed." << std::endl;
	}
}

Dog&	Dog::operator=(const Dog& obj)
{
	if (this == &obj)
	{
		std::cout << "Copy assignment for itself. refused." << std::endl;
		return (*this);
	}
	else
	{
		this->type = obj.type;
		std::cout << this->type << " Dog class is copy-assigned." << std::endl;
		return (*this);
	}
}

Dog::~Dog(void)
{
	std::cout << this->type << " Dog class is destructed." << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "Bark!" << std::endl;
}


int main(void)
{
	Cat*	i = new Cat();
	i->makeSound();
	delete i;
}


// int	main(void)
// {
// 	const Animal*	meta = new Animal();
// 	const Animal*	j = new Dog();
// 	const Animal*	i = new Cat();

// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound();
// 	j->makeSound();
// 	meta->makeSound();

// 	return (0);
// }