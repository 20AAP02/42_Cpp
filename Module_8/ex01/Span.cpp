#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span(): _maxSize(0), _size(0)
{
}

Span::Span(unsigned int N): _maxSize(N), _size(0)
{
}

Span::Span( const Span & src ): _maxSize(src.getMaxSize()), _size(src.getSize())
{
	const std::set<int> ex = src.getSet();
	for (std::set<int>::iterator iter= ex.begin(); iter != ex.end(); iter++)
		this->set.insert(*iter);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		const std::set<int> ex = rhs.getSet();
		int i = 0;
		this->set.clear();
		for (std::set<int>::iterator iter= ex.begin(); iter != ex.end() && i < (int)this->_maxSize; iter++ )
		{
			this->set.insert(*iter);
			i++;
		}
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Span const & i )
{
	const std::set<int> ex = i.getSet();
	o << "(";
	for (std::set<int>::iterator iter= ex.begin(); iter != ex.end(); iter++ )
		o << *iter << "; ";
	o << "\b\b)";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Span::addNumber(const int number)
{
	if (this->_size < this->_maxSize)
	{
		this->set.insert(number);
		this->_size++;
	}
	else
		throw Span::MaxLenReachedException();
}

void Span::addNumbers(std::set<int>::iterator begin, std::set<int>::iterator end)
{
	for (std::set<int>::iterator iter = begin; iter != end; iter++)
		this->addNumber(*iter);
}

int Span::shortestSpan()
{
	return 0;
}

int Span::longestSpan()
{
	return 1;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

unsigned int Span::getMaxSize() const
{
	return this->_maxSize;
}

unsigned int Span::getSize() const
{
	return this->_size;
}


const std::set<int> Span::getSet() const
{
	return this->set;
}

/* ************************************************************************** */