#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>

template <class T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack &src): std::stack<T>(src) {}
		~MutantStack() {}

		MutantStack &		operator=( MutantStack const & rhs ) {
			std::stack<T>::operator=(rhs);
			return *this;
		}

		typedef class std::deque<T>::iterator iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}
};

#endif /* ***************************************************** MUTANTSTACK_H */