#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal: Default constructor called\n";
}

Animal::Animal( const Animal & src )
{
	this->type = src.type;
	std::cout << "Animal: Copy constructor called\n";

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal: destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal				&Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		std::cout << "Animal: Copy assignment operator called\n";
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Animal: made sound\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */