#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>

#define SIZE 2

int main()
{
	const Animal *animals[SIZE];

	std::cout << "------ Constructors ------\n";
	for (int i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog();
	for (int i = SIZE / 2; i < SIZE; i++)
		animals[i] = new Cat();
	std::cout << "------ Methods ------\n";
	// Animal a;
	// const Animal *a = new Animal();
	((Dog *)animals[0])->setIdea(0, "Im a dog!");
	Dog dog = *((Dog *)animals[0]);
	std::cout << "--- Ideas after copy ---\n";
	std::cout << dog.getIdea(0) << std::endl;
	std::cout << ((Dog *)animals[0])->getIdea(0) << std::endl;
	dog.setIdea(0, "Im a human!");
	std::cout << "--- Ideas after change ---\n";
	std::cout << dog.getIdea(0) << std::endl;
	std::cout << ((Dog *)animals[0])->getIdea(0) << std::endl;
	std::cout << "------ Deconstructors ------\n";
	for (int i = 0; i < SIZE; i++)
		delete animals[i];
}