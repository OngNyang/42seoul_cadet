#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// delete j;//should not create a leak delete i;
	// ...

	int num_arr = 2;
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

//strong-point : reusable
	std::cout << std::endl;
	Dog	*copy_dog;
	copy_dog = dynamic_cast<Dog*>(arr[0]);
	std::string	temp_str = copy_dog->getBrain(0);
	std::cout << "no 0 idea is " << temp_str << std::endl;
	copy_dog->setBrain("hello world", 0);
	temp_str = copy_dog->getBrain(0);
	std::cout << "no 0 idea is " << temp_str << std::endl;

//make sound
	std::cout << std::endl;
	for (int i=0; i<num_arr; i++)
	{
		std::cout << arr[i]->getType() << std::endl;
		arr[i]->makeSound();
	}

//delete
	std::cout << std::endl;
	for (int i=0; i<num_arr; i++)
		delete arr[i];

	// system("leaks set_the_world_on_fire");
	return 0;
}