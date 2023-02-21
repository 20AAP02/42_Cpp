#include "Literal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Literal::Literal()
{
}

Literal::Literal(const std::string literal)
{

}

Literal::Literal( const Literal & src )
{
	this->_literal = src._literal;
	this->_char = src._char;
	this->_int = src._int;
	this->_float = src._float;
	this->_double = src._double;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Literal::~Literal()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Literal &				Literal::operator=( Literal const & rhs )
{
	if ( this != &rhs )
	{
		this->_literal = rhs._literal;
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Literal const & i )
{
	o << i._literal;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

std::string Literal::getType(const std::string arg) const
{
	const std::string pseudoFloats[] = {"-inff", "+inff", "nanf"};
	const std::string pseudoDoubles[] = {"-inf", "+inf", "nan"};
	if (std::isdigit(arg[0]))
	{
		if (arg[arg.length() - 1] == 'f')
			return "float";
		if (arg.find(".") != arg.npos)
			return "double";
		return "int";
	}
	for (int i = 0; i < 3; i++)
		if (arg == pseudoFloats[i])
			return "floatP";
	for (int i = 0; i < 3; i++)
		if (arg == pseudoDoubles[i])
			return "doubleP";
	return "char";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */