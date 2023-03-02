#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <set>
# include <iterator>

class Span
{

	public:

		Span(unsigned int N);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );

		unsigned int getMaxSize() const;
		unsigned int getSize() const;
		const std::set<int> getSet() const;
		
		void addNumber(const int number);
		void addNumbers(std::set<int>::iterator begin, std::set<int>::iterator end);
		int shortestSpan();
		int longestSpan();

		class MaxLenReachedException : public std::exception {
			public: virtual const char* what() const throw() {
				return "Span has reached max size!";
			}
		};

	private:
		Span();
		std::set<int> set;
		const unsigned int _maxSize;
		unsigned int _size;


};

std::ostream &			operator<<( std::ostream & o, Span const & i );

#endif /* ************************************************************ SPAN_H */