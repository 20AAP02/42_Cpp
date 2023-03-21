#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	this->_vctSequence = src.getVector();
	this->_lstSequence = src.getList();
	this->_originalSqc = src.getOriginalSqc();

}

PmergeMe::PmergeMe(const char **sequence)
{
	int i = -1;
	while (sequence[++i])
	{
		std::string str(sequence[i]);
		if (str.size() >= 10 && str > "2147483647")
			fterror("too big of a number.");
		int number = atoi(sequence[i]);
		if (number < 0)
			fterror("non positive integer.");
		if (str.find_first_not_of("0123456789") != str.npos)
			fterror("non digit found in input.");
		this->_lstSequence.push_back((unsigned int)number);
		this->_vctSequence.push_back((unsigned int)number);
		this->_originalSqc.push_back((unsigned int)number);
	}

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	if ( this != &rhs )
	{
		this->_vctSequence = rhs.getVector();
		this->_lstSequence = rhs.getList();
		this->_originalSqc = rhs.getOriginalSqc();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
{
	std::list<unsigned int> lst = i.getList();
	std::vector<unsigned int> vec = i.getOriginalSqc();

	o << "Before: ";
	for (std::vector<unsigned int>::iterator iter= vec.begin(); iter != vec.end(); iter++)
	{
		o << *iter << " ";
	}
	o << std::endl << "After: ";
	for (std::list<unsigned int>::iterator iter= lst.begin(); iter != lst.end(); iter++)
	{
		o << *iter << " ";
	}
	std::cout << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int PmergeMe::fterror(const std::string msg) const
{
	std::cout << "Error: " << msg << std::endl;
	throw PmergeMe::ErrorException();
}

std::list<unsigned int> PmergeMe::sortList()
{
}

std::vector<unsigned int> PmergeMe::sortVector()
{
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::vector<unsigned int> PmergeMe::getVector() const
{
	return this->_vctSequence;
}

std::list<unsigned int> PmergeMe::getList() const
{
	return this->_lstSequence;
}

std::vector<unsigned int> PmergeMe::getOriginalSqc() const
{
	return this->_originalSqc;
}

/* ************************************************************************** */