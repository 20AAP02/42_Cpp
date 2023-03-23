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

std::string PmergeMe::sortList()
{
	clock_t start = clock();
	// Clock started

	// this->_lstSequence.sort();
	// Clock stoped
	clock_t end = clock();
	std::string time =  SSTR("Time to process a range of " << this->_lstSequence.size() << " elements with std::list : " << float(end - start)/CLOCKS_PER_SEC << " sec\n");
	return time;

}

void printVectorOfVectors(std::vector<std::vector<unsigned int> > vectOfSequences)
{
	std::cout << "------------------------------------------------------------\n";
	for (int i = 0; i < (int)vectOfSequences.size(); i++)
	{
		std::cout << "[";
		for (int j = 0; j < (int)vectOfSequences[i].size(); j++)
		{
			std::cout << vectOfSequences[i][j];
			if (j < (int)vectOfSequences[i].size() - 1)
				std::cout << ",";
		}
		std::cout << "]\n";
	}
}

std::vector<std::vector<unsigned int> > &divideVector(std::vector<std::vector<unsigned int> > &sqc, int k)
{
	if (k == 0)
		return sqc;
	if ((int)sqc[0].size() <= k)
	{
		std::vector<unsigned int> newVector = sqc[0];
		sqc.erase(sqc.begin());
		sqc.push_back(newVector);
		return divideVector(sqc, 0);
	}
	if ((int)sqc[0].size() > k)
	{
		std::vector<unsigned int> newVector;
		for (int i = 0; i < k; i++)
			newVector.push_back(sqc[0][i]);
		sqc[0].erase(sqc[0].begin(), sqc[0].begin() + k);
		sqc.push_back(newVector);
		return divideVector(sqc, k);
	}
	return sqc;
}

std::vector<unsigned int> &insertionSort(std::vector<unsigned int> &sqc)
{
	for (int i = 0; i < (int)sqc.size(); i++)
	{
		if (i == 0)
			continue;
		if (sqc[i - 1] > sqc[i])
		{
			std::swap(sqc[i - 1], sqc[i]);
			i -= 2;
		}
	}
	return sqc;
}

std::vector<std::vector<unsigned int> > &mergeSort(std::vector<std::vector<unsigned int> > &sqc)
{
	if ((int)sqc.size() > 2)
	{
		std::vector<std::vector<unsigned int> > newSqc;
		newSqc.push_back(*(sqc.begin()));
		newSqc.push_back(*(sqc.begin() + 1));
		sqc.erase(sqc.begin(), sqc.begin() + 2);
		newSqc = mergeSort(newSqc);
		sqc.push_back(newSqc[0]);
		return mergeSort(sqc);
	}
	if ((int)sqc.size() == 2)
	{
		std::vector<unsigned int> sortedVector;
		while ((int)sqc[0].size() > 0 && (int)sqc[1].size() > 0)
		{
			if (*(sqc[0].begin()) < *(sqc[1].begin()))
			{
				sortedVector.push_back(*(sqc[0].begin()));
				sqc[0].erase(sqc[0].begin());
			}
			else
			{
				sortedVector.push_back(*(sqc[1].begin()));
				sqc[1].erase(sqc[1].begin());
			}
		}
		for (int i = 0; i < (int)sqc[0].size(); i++)
			sortedVector.push_back(sqc[0][i]);
		for (int i = 0; i < (int)sqc[1].size(); i++)
			sortedVector.push_back(sqc[1][i]);
		sqc.erase(sqc.begin(), sqc.begin() + 2);
		sqc.push_back(sortedVector);
	}
	return sqc;
}

std::string PmergeMe::sortVector()
{
	clock_t start = clock();
	// Clock started
	std::vector<unsigned int> vec = this->_vctSequence;
	//  divide the given N elements of array into (N/K) groups of each group of size K
	std::vector<std::vector<unsigned int> > vectOfSequences;
	vectOfSequences.push_back(vec);
	vectOfSequences = divideVector(vectOfSequences, 2);
	for (int i = 0;  i < (int)vectOfSequences.size(); i++)
		insertionSort(vectOfSequences[i]);
	vectOfSequences = mergeSort(vectOfSequences);
	// Clock stoped
	clock_t end = clock();
	std::string time =  SSTR("Time to process a range of " << this->_vctSequence.size() << " elements with std::vector : " << float(end - start)/CLOCKS_PER_SEC << " sec\n");
	return time;
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