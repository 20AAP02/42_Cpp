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

// Sort functions for list

std::list<unsigned int>::iterator get(std::list<unsigned int> &_list, int index)
{
	std::list<unsigned int>::iterator it = _list.begin();
    for(int i = 0; i < index; i++)
	{
        it++;
    }
    return it;
}

std::list<std::list<unsigned int> >::iterator get(std::list<std::list<unsigned int> > &_list, int index)
{
	std::list<std::list<unsigned int> >::iterator it = _list.begin();
    for(int i = 0; i < index; i++){
        ++it;
    }
    return it;
}

void printList(std::list<unsigned int> &lst)
{
	std::list<unsigned int>::iterator it = lst.begin();
	std::cout << "-- list size: " << (int)lst.size() << " --\n";
    for(int i = 0; i < (int)lst.size(); i++)
	{
		std::cout << *it;
		std::cout << ",";
        it++;
    }
	std::cout << std::endl;
}

void printListOfList(std::list<std::list<unsigned int> > listOfSequences)
{
	std::cout << "------------------------------------------------------------\n";
	std::cout << "-\n";
	for (std::list<std::list<unsigned int> >::iterator it = listOfSequences.begin(); it != listOfSequences.end(); ++it)
	{
		std::cout << "[";
		for (std::list<unsigned int>::iterator itScd = it->begin(); itScd != it->end(); ++itScd)
		{
			std::cout << *itScd;
			std::cout << ",";
		}
		std::cout << "]\n";
	}
	std::cout << "-\n";
}

std::list<std::list<unsigned int> > &divideList(std::list<std::list<unsigned int> > &sqc, int k)
{
	if (k == 0)
		return sqc;
	if ((int)sqc.front().size() <= k)
	{
		sqc.push_back(sqc.front());
		sqc.erase(sqc.begin());
		return divideList(sqc, 0);
	}
	std::list<unsigned int> newList;
	for (int i = 0; i < k; i++)
		newList.push_back(*(get(sqc.front(), i)));
	for (int i = 0; i < k; i++)
		sqc.front().pop_front();
	sqc.push_back(newList);
	return divideList(sqc, k);
}

std::list<unsigned int> &insertionSortList(std::list<unsigned int> &sqc)
{
	std::list<unsigned int>::iterator next = sqc.begin();
	next++;
	std::list<unsigned int>::iterator mem;
	for (std::list<unsigned int>::iterator current = sqc.begin(); current != sqc.end(); )
	{
		if (*current > *next)
		{
			std::swap(*current, *next);
			if (current != sqc.begin())
				next--;
			if (current != sqc.begin())
				current--;
		}
		else
		{
			next++;
			current++;
		}
	}
	return sqc;
}

std::list<std::list<unsigned int> > &mergeSortList(std::list<std::list<unsigned int> > &sqc)
{
	if ((int)sqc.size() > 2)
	{
		std::list<std::list<unsigned int> > newSqc;
		for (int i = 0; i < 2; i++)
		{
			newSqc.push_back(sqc.front());
			sqc.pop_front();
		}
		newSqc = mergeSortList(newSqc);
		sqc.push_back(newSqc.front());
		return mergeSortList(sqc);
	}
	if ((int)sqc.size() == 2)
	{
		std::list<unsigned int> sortedVector;
		std::list<unsigned int> &firstLst = sqc.front();
		std::list<unsigned int> &secondLst = *(get(sqc, 1));
		while ((int)firstLst.size() > 0 && (int)secondLst.size() > 0)
		{
			if (firstLst.front() < secondLst.front())
			{
				sortedVector.push_back(firstLst.front());
				firstLst.pop_front();
			}
			else
			{
				sortedVector.push_back(secondLst.front());
				secondLst.pop_front();
			}
		}
		for (int i = 0; i < (int)firstLst.size(); i++)
			sortedVector.push_back((*(get(firstLst, i))));
		for (int i = 0; i < (int)secondLst.size(); i++)
			sortedVector.push_back((*(get(secondLst, i))));
		for (int i = 0; i < 2; i++)
			sqc.pop_front();
		sqc.push_back(sortedVector);
	}
	return sqc;
}

std::string PmergeMe::sortList()
{
	clock_t start = clock();
	// Clock started
	std::list<unsigned int> lst = this->_lstSequence;
	std::list<std::list<unsigned int> > lstOfSequences;
	lstOfSequences.push_back(lst);
	lstOfSequences = divideList(lstOfSequences, 2);
	// printListOfList(lstOfSequences);
	for (std::list<std::list<unsigned int> >::iterator it = lstOfSequences.begin(); it != lstOfSequences.end(); it++)
		insertionSortList(*it);
	// printListOfList(lstOfSequences);
	lstOfSequences = mergeSortList(lstOfSequences);
	this->_lstSequence = lstOfSequences.front();
	// Clock stoped
	clock_t end = clock();
	std::string time =  SSTR("Time to process a range of " << this->_lstSequence.size() << " elements with std::list : " << float(end - start)/CLOCKS_PER_SEC << " sec\n");
	return time;

}

// Sort functions for vector

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
		sqc.push_back(sqc[0]);
		sqc.erase(sqc.begin());
		return divideVector(sqc, 0);
	}
	std::vector<unsigned int> newVector;
	for (int i = 0; i < k; i++)
		newVector.push_back(sqc[0][i]);
	sqc[0].erase(sqc[0].begin(), sqc[0].begin() + k);
	sqc.push_back(newVector);
	return divideVector(sqc, k);
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
	std::vector<std::vector<unsigned int> > vectOfSequences;
	vectOfSequences.push_back(vec);
	vectOfSequences = divideVector(vectOfSequences, 190);
	for (int i = 0;  i < (int)vectOfSequences.size(); i++)
		insertionSort(vectOfSequences[i]);
	vectOfSequences = mergeSort(vectOfSequences);
	this->_vctSequence = vectOfSequences[0];
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