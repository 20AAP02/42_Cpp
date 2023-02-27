#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <class type>
void swap(type &a, type &b)
{
	type c = b;

	b = a;
	a = c;
}

template <class type>
type &min(type &a, type &b)
{
	if (a < b)
		return a;
	return b;
}

template <class type>
type &max(type &a, type &b)
{
	if (a > b)
		return a;
	return b;
}

#endif