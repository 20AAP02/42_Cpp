#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>
# include <iterator>
# include <cstdio>
# include <ctime>
# include <iomanip>
# include <sstream>

#define SSTR(x) static_cast< std::ostringstream & >((std::ostringstream() << std::dec << x)).str()

class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		PmergeMe(const char **sequence);
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		class ErrorException : public std::exception {
			public: virtual const char* what() const throw() {
				return "PmergeMe Error";
			}
		};

		std::vector<unsigned int> getVector() const;
		std::list<unsigned int> getList() const;
		std::vector<unsigned int> getOriginalSqc() const;

		int fterror(const std::string msg) const;
		std::string sortList();
		std::string sortVector();

	private:
		std::vector<unsigned int> _originalSqc;
		std::vector<unsigned int> _vctSequence;
		std::list<unsigned int> _lstSequence;



};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */