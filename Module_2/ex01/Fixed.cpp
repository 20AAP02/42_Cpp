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

int setExpInt(const int n, int exp)
{
	exp = exp << 15;
	return (n | exp);
}

int lenInt(int n)
{
	int i;
	for (i = 0; n > 0; i++)
		n /= 10;
	return i;
}

int MantissaDivider(int len)
{
	int d = 1;
	for (int i = 0; i < len; i++)
		d *= 10;
	return d;
}

float mantissaConv(int m)
{
	return (float)m / (float)MantissaDivider(lenInt(m));
}

int formatInt(int n)
{
	int formatedInt = 0;
	int exp = -126;
	int mantissa = 0;
	// if (n < 0)
	// {
	// 	n *= -1;
	// 	formatedInt = 1;
	// 	formatedInt = formatedInt << 31;
	// }
	formatedInt = n;
	for (mantissa = 0; mantissa < 100; mantissa++)
	{
		for (exp = -126; exp < 128; exp++)
		{
			if (n == (int)(roundf(1.0 + mantissaConv(mantissa)) * (float)pow(2, exp)))
			{
				std::cout << (int)(roundf(1.0 + mantissaConv(mantissa)) * (float)pow(2, exp)) << std::endl;
				break;
			}
		}
	}
	exp += 127;
	return setExpInt(formatedInt, exp);
}

// usefull

int pow(int x, int n)
{
	if (n == 0)
		return 1;
	for (int i = 1; i < n; i++)
		x *= x;
	return x;
}

int getExponent(float n)
{
	n = n >> 23;
	n = n & 255;
	return n;
}

int getMantissa(float n)
{
	n = n & 8388607;

}

Fixed::Fixed(const int n)
{
	Fixed::value = n;
}

Fixed::Fixed(const float n)
{
	
}

float Fixed::toFloat(void) const
{
	return 0.0f;
}

int Fixed::toInt(void) const
{
	return 0;
}