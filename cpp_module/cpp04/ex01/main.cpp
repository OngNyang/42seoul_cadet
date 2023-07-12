// #include "Dog.hpp"
// #include "Cat.hpp"

// int main()
// {
// 	// const Animal* j = new Dog();
// 	// const Animal* i = new Cat();

// 	// delete j;//should not create a leak delete i;
// 	// ...

// 	int num_arr = 2;
// 	std::cout << "there are " << num_arr << " animals." << std::endl;
// 	std::cout << std::endl;

// 	Animal	*arr[num_arr];
// 	for (int i=0; i<num_arr; i++)
// 	{
// 		if (i % 2 == 0)
// 			arr[i] = new Dog();
// 		else
// 			arr[i] = new Cat();
// 	}
// 	std::cout << std::endl;

// //strong-point : reusable
// 	std::cout << std::endl;
// 	Dog	*copy_dog;
// 	copy_dog = dynamic_cast<Dog*>(arr[0]);
// 	std::string	temp_str = copy_dog->getBrain(0);
// 	std::cout << "no 0 idea is " << temp_str << std::endl;
// 	copy_dog->setBrain("hello world", 0);
// 	temp_str = copy_dog->getBrain(0);
// 	std::cout << "no 0 idea is " << temp_str << std::endl;

// //make sound
// 	std::cout << std::endl;
// 	for (int i=0; i<num_arr; i++)
// 	{
// 		std::cout << arr[i]->getType() << std::endl;
// 		arr[i]->makeSound();
// 	}

// //delete
// 	std::cout << std::endl;
// 	for (int i=0; i<num_arr; i++)
// 		delete arr[i];

// 	// system("leaks set_the_world_on_fire");
// 	return 0;
// }





// #include "Dog.hpp"
// #include "Cat.hpp"
// int main()
// {
//     // const Animal* j = new Dog();
//     // const Animal* i = new Cat();
//     // delete j;//should not create a leak delete i;
//     // ...



// //     Animal* temp = new Dog();
// //     Animal* temp2 = new Dog();
// //     temp + temp2;
// //     int num_arr = 2;
// //     std::cout << "there are " << num_arr << " animals." << std::endl;
// //     std::cout << std::endl;
// //     Animal  *arr[num_arr];
// //     for (int i=0; i<num_arr; i++)
// //     {
// //         if (i % 2 == 0)
// //             arr[i] = new Dog();
// //         else
// //             arr[i] = new Cat();
// //     }
// //     std::cout << std::endl;
// // //strong-point : reusable
// //     std::cout << std::endl;
// //     Dog *copy_dog;
// //     copy_dog = dynamic_cast<Dog*>(arr[0]);
// //     std::string temp_str = copy_dog->getBrain(0);
// //     std::cout << "no 0 idea is " << temp_str << std::endl;
// //     copy_dog->setBrain("hello world", 0);
// //     temp_str = copy_dog->getBrain(0);
// //     std::cout << "no 0 idea is " << temp_str << std::endl;




// // //make sound
// //     std::cout << std::endl;
// //     for (int i=0; i<num_arr; i++)
// //     {
// //         std::cout << arr[i]->getType() << std::endl;
// //         arr[i]->makeSound();
// //     }
// // //delete
// //     std::cout << std::endl;
// //     for (int i=0; i<num_arr; i++)
// //         delete arr[i];


// //     // Dog  basic;
// //     // {
// //     //  Dog temp = basic;
// //     // }
// //     // basic.getBrain(0);
// //     // while(1)
// //     // {
// //     // }


// 	Dog	basic;
// 	basic.setBrain("hello_world", 0);
// 	{
// 		Dog temp = basic;
// 	}
// 	std::cout << basic.getBrain(0) << std::endl;
// 	while(1)
// 	{
// 	}

// 	// Dog *temp = copy_dog;
// 	// std::cout << "-----" << temp->getBrain(0) << std::endl;
// 	// std::cout << std::endl;
// 	// std::cout << std::endl;
// 	// std::cout << std::endl;
// 	// std::cout << std::endl;
// 	// delete temp;
// 	// std::cout << "-----" << copy_dog->getBrain(0) << std::endl;





//     // system("leaks set_the_world_on_fire");
//     return 0;
// }




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
    Animal  *arr[num_arr];
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
    Dog *copy_dog;
    copy_dog = dynamic_cast<Dog*>(arr[0]);
    std::string temp_str = copy_dog->getBrain(0);
    std::cout << "no 0 idea is " << temp_str << std::endl;
    copy_dog->setBrain("hello world", 0);
    temp_str = copy_dog->getBrain(0);
    std::cout << "no 0 idea is " << temp_str << std::endl;


 Dog *pup = copy_dog;
 std::cout << "-----" << pup->getBrain(0) << std::endl;
 std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << std::endl;
 delete pup;
 std::cout << "-----" << copy_dog->getBrain(0) << std::endl;


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
    // Dog  basic;
    // {
    //  Dog temp = basic;
    // }
    // basic.getBrain(0);
    // while(1)
    // {
    // }
    system("leaks set_the_world_on_fire");
    return 0;
}