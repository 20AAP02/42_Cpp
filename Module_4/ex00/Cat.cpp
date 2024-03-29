#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat: Default constructor called\n";
}

Cat::Cat( const Cat & src ): Animal(src)
{
	std::cout << "Cat: Copy constructor called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
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


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */