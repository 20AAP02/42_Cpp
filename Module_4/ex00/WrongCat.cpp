#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat: Default constructor called\n";
}

WrongCat::WrongCat( const WrongCat & src ): WrongAnimal(src)
{
	std::cout << "WrongCat: Copy constructor called\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor called\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
		std::cout << "WrongCat: Copy assignment operator called\n";
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void WrongCat::makeSound() const
{
	std::cout << "WrongCat: made sound\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */