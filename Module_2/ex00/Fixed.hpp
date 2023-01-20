#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int value;
	const static int fractionalBits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif