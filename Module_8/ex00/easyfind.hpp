#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
// # include <list>
// # include <map>

template <class T>
T &easyfind(const T &container, const int toFind)
{
	typename T::iterator itr = std::find(container.begin(), container.end(), toFind);
}

#endif