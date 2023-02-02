#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	this->type = "Default Animal";
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
	std::cout << "Animal: Deconstructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

void				Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		std::cout << "Animal: Copy assignment operator called\n";
	}
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Animal::getType() const
{
	return this->type;
}

void Animal::setType(std::string type)
{
	this->type = type;
	std::cout << "Animal: Set type to " << type << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */