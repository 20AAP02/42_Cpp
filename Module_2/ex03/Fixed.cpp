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

// Ex01

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

// Ex02

// The 6 comparison operators

bool Fixed::operator >(const Fixed &F)
{
	if (value > F.getRawBits())
		return true;
	return false;
}

bool Fixed::operator <(const Fixed &F)
{
	if (value < F.getRawBits())
		return true;
	return false;
}

bool Fixed::operator >=(const Fixed &F)
{
	if (value >= F.getRawBits())
		return true;
	return false;
}

bool Fixed::operator <=(const Fixed &F)
{
	if (value <= F.getRawBits())
		return true;
	return false;
}

bool Fixed::operator ==(const Fixed &F)
{
	if (value == F.getRawBits())
		return true;
	return false;
}

bool Fixed::operator !=(const Fixed &F)
{
	if (value != F.getRawBits())
		return true;
	return false;
}

// The 4 arithmetic operators

Fixed Fixed::operator +(const Fixed &F)
{
	Fixed ex(this->toFloat() + F.toFloat());
	return ex;
}

Fixed Fixed::operator -(const Fixed &F)
{
	Fixed ex(this->toFloat() - F.toFloat());
	return ex;
}

Fixed Fixed::operator *(const Fixed &F)
{
	Fixed ex(this->toFloat() * F.toFloat());
	return ex;
}

Fixed Fixed::operator /(const Fixed &F)
{
	Fixed ex;
	ex.setRawBits(value * F.getRawBits());
	return ex;
}

// The 4 increment/decrement

// Post-fix

Fixed Fixed::operator ++(int i)
{
	(void) i;
	Fixed ex;
	ex.setRawBits(value);
	value++;
	return ex;
}

Fixed Fixed::operator --(int i)
{
	(void) i;
	Fixed ex;
	ex.setRawBits(value);
	value--;
	return ex;
}

// Pre-fix

Fixed Fixed::operator ++()
{
	value++;
	Fixed ex;
	ex.setRawBits(value);
	return ex;
}

Fixed Fixed::operator --()
{
	value--;
	Fixed ex;
	ex.setRawBits(value);
	return ex;
}

// Four public overloaded member functions

Fixed &Fixed::min(Fixed &F1, Fixed &F2)
{
	if (F1.toFloat() <= F2.toFloat())
		return F1;
	else
		return F2;
}

const Fixed &Fixed::min(const Fixed &F1, const Fixed &F2)
{
	if (F1.toFloat() <= F2.toFloat())
		return F1;
	else
		return F2;
}

Fixed &Fixed::max(Fixed &F1, Fixed &F2)
{
	if (F1.toFloat() >= F2.toFloat())
		return F1;
	else
		return F2;
}

const Fixed &Fixed::max(const Fixed &F1, const Fixed &F2)
{
	if (F1.toFloat() >= F2.toFloat())
		return F1;
	else
		return F2;
}
