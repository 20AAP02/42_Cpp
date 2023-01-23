#include <Fixed.hpp>

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	Fixed::value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return Fixed::value;
}

void Fixed::setRawBits(int const raw)
{
	Fixed::value = raw;
}

Fixed::Fixed(const Fixed &F)
{
	std::cout << "Copy constructor called\n";
	Fixed::value = F.getRawBits();
}

void Fixed::operator=(const Fixed &F)
{
	std::cout << "Copy assignment operator called\n";
	value = F.getRawBits();
}
