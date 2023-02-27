#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <class T>
void iter(T *array, std::size_t len, void (*func)(T&))
{
	for (std::size_t i = 0; i < len; i++)
		func(array[i]);
}

#endif