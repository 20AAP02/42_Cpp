#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int main()
{
	{
		std::cout << "---------- Right Animals ----------\n";
		std::cout << "-- Constructors --\n";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "-- Types --\n";
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "-- Sounds --\n";
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();
		std::cout << "-- Deconstructors --\n";
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "\n---------- Wrong Animals ----------\n";
		std::cout << "-- Constructors --\n";
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		const WrongCat c;
		std::cout << "-- Types --\n";
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << "-- Sounds --\n";
		i->makeSound(); // will output the animal sound!
		((WrongCat *) i)->makeSound(); // will output the cat sound!
		meta->makeSound();
		c.makeSound();
		std::cout << "-- Deconstructors --\n";
		delete meta;
		delete i;
		return 0;
	}
}
