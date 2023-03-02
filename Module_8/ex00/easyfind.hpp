#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>

class CantFindElementException : public std::exception {
	public: virtual const char* what() const throw() {
		return "easyfind: Can not find element in container!";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int toFind)
{
	typename T::iterator ptr = std::find(container.begin(), container.end(), toFind);
	if (ptr == container.end())
		throw CantFindElementException();
	return ptr;
	
}

#endif