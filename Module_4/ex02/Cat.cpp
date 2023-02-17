#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat: Default constructor called\n";
}

Cat::Cat( const Cat & src ): Animal(src)
{
	this->brain = new Brain(*(src.brain));
	std::cout << "Cat: Copy constructor called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat: destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		*(this->brain) = *(rhs.brain);
		std::cout << "Cat: Copy assignment operator called\n";
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat: made sound\n";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Cat::getIdea(unsigned int i) const
{
	return this->brain->ideas[i % 100];

}

void Cat::setIdea(unsigned int i, std::string idea)
{
	this->brain->ideas[i % 100] = idea;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */