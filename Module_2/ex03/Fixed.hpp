#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <math.h> // Allowed function : float roundf(float x)

class Fixed
{
private:
	int value;
	const static int fractionalBits = 8;
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

	bool operator >(const Fixed &F);
	bool operator <(const Fixed &F);
	bool operator >=(const Fixed &F);
	bool operator <=(const Fixed &F);
	bool operator ==(const Fixed &F);
	bool operator !=(const Fixed &F);
	Fixed operator +(const Fixed &F);
	Fixed operator -(const Fixed &F);
	Fixed operator *(const Fixed &F);
	Fixed operator /(const Fixed &F);
	Fixed operator ++(int i);
	Fixed operator --(int i);
	Fixed operator ++();
	Fixed operator --();
	static Fixed &min(Fixed &F1, Fixed &F2);
	static const Fixed &min(const Fixed &F1, const Fixed &F2);
	static Fixed &max(Fixed &F1, Fixed &F2);
	static const Fixed &max(const Fixed &F1, const Fixed &F2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif