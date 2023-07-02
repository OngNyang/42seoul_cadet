#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main(void)
// {
// 	Cat*	i = new Cat();
// 	i->makeSound();
// 	delete i;
// }


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

	delete meta;
	delete j;
	delete i;

//--------wrong Animal, wrong Cat-----------
	std::cout << "------Wrong class test------" << std::endl;
	const WrongAnimal*	wrong_meta = new WrongAnimal();
	const WrongAnimal*	wrong_i = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound();
	wrong_meta->makeSound();

	delete wrong_i;
	delete wrong_meta;
	return (0);
}
