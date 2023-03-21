#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <list>
# include <iterator>

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
		std::list<unsigned int> sortList();
		std::vector<unsigned int> sortVector();

	private:
		std::vector<unsigned int> _originalSqc;
		std::vector<unsigned int> _vctSequence;
		std::list<unsigned int> _lstSequence;



};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */