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
	value = n << fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called\n";
	value = roundf(n * (1 << fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return (value >> fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
