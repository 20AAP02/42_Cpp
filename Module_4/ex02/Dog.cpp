#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog: Default constructor called\n";
}

Dog::Dog( const Dog & src ): Animal(src)
{
	this->brain = new Brain(*(src.brain));
	std::cout << "Dog: Copy constructor called\n";
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog: Deconstructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		*(this->brain) = *(rhs.brain);
		std::cout << "Dog: Copy assignment operator called\n";
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Dog::makeSound() const
{
	std::cout << "Dog: made sound\n";
}

std::string Dog::getIdea(unsigned int i) const
{
	return this->brain->ideas[i % 100];

}

void Dog::setIdea(unsigned int i, std::string idea)
{
	this->brain->ideas[i % 100] = idea;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */