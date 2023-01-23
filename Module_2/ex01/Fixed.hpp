#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h> // Allowed function : float roundf(float x)

class Fixed
{
private:
	int value;
	const static int fractionalBits;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &F);
	void operator=(const Fixed &F);
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int n);
	Fixed(const float n);
	float toFloat(void) const;
	int toInt(void) const;
};

#endif