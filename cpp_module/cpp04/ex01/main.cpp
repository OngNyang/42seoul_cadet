#include "Dog.hpp"
#include "Cat.hpp"

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

// 	delete meta;
// 	delete j;
// 	delete i;

// //--------wrong Animal, wrong Cat-----------
// 	std::cout << "------Wrong class test------" << std::endl;
// 	const WrongAnimal*	wrong_meta = new WrongAnimal();
// 	const WrongAnimal*	wrong_i = new WrongCat();

// 	std::cout << wrong_i->getType() << " " << std::endl;
// 	wrong_i->makeSound();
// 	wrong_meta->makeSound();

// 	delete wrong_i;
// 	delete wrong_meta;
// 	return (0);
// }

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// delete j;//should not create a leak delete i;
	// ...

	int num_arr = 4;
	std::cout << "there are " << num_arr << " animals." << std::endl;
	std::cout << std::endl;

	Animal	*arr[num_arr];
	for (int i=0; i<num_arr; i++)
	{
		if (i % 2 == 0)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}
	std::cout << std::endl;

	std::cout << std::endl;
//copy-assignment
	// Animal	copy_dog;
	// copy_dog = *(arr[0]);

	std::cout << std::endl;

	for (int i=0; i<num_arr; i++)
	{
		std::cout << arr[i]->getType() << std::endl;
		arr[i]->makeSound();
	}

	std::cout << std::endl;

	for (int i=0; i<num_arr; i++)
		delete arr[i];

	// system("leaks set_the_world_on_fire");
	return 0;
}