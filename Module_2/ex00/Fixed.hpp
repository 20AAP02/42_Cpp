#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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
};

#endif