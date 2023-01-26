#include <Fixed.hpp>

const static int fractionalBits = 8;

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

// ex01

int pow(int x, int n)
{
	if (n == 0)
		return 1;
	for (int i = 1; i < n; i++)
		x *= x;
	return x;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	value = n << 8;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	value = n;
}

float Fixed::toFloat(void) const
{
	return 0.0f;
}

int Fixed::toInt(void) const
{
	return (value >> 8);
}