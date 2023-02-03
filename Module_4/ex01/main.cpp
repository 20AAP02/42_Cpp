#include <Animal.hpp>
#include <Dog.hpp>
#include <Cat.hpp>
#include <Brain.hpp>

#define SIZE 2

int main()
{
	Animal *animals[SIZE];

	std::cout << "------ Constructors ------\n";
	for (int i = 0; i < SIZE / 2; i++)
		animals[i] = new Dog();
	for (int i = SIZE / 2; i < SIZE; i++)
		animals[i] = new Cat();
	std::cout << "------ Methods ------\n";
	animals[0]->getIdea(0);
	std::cout << "------ Deconstructors ------\n";
	for (int i = 0; i < SIZE; i++)
		delete animals[i];
}