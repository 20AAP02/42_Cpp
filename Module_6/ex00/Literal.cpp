#include "Literal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Literal::Literal()
{
	this->_char = 0;
	this->_int = 0;
	this->_float = 0;
	this->_double = 0;
}

Literal::Literal(const std::string literal)
{
	this->_literal = literal;
	this->_char = 0;
	this->_int = 0;
	this->_float = 0;
	this->_double = 0;
	this->_originalType = this->convertToOriginalType(literal);
	if (this->_originalType == "char")
		this->convert(this->_char);
	else if (this->_originalType == "int")
		this->convert(this->_int);
	else if (this->_originalType == "float" || this->_originalType == "floatP")
		this->convert(this->_float);
	else if (this->_originalType == "double" || this->_originalType == "doubleP")
		this->convert(this->_double);
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
	if (std::isdigit(arg[0]) || (arg.length() > 1 && std::isdigit(arg[1])))
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

std::string Literal::convertToOriginalType(const std::string literal)
{
	std::string type = this->getType(literal);

	if (type == "char")
		this->_char = literal[0];
	else if (type == "int")
		this->_int = atoi(literal.c_str());
	else if (type == "float" || type == "floatP")
		this->_float = static_cast<float>(atof(literal.c_str()));
	else if (type == "double" || type == "doubleP")
		this->_double = atof(literal.c_str());
	return type;
}

void Literal::convert(char literal)
{
	this->_int = static_cast<int>(literal);
	this->_float = static_cast<float>(literal);
	this->_double = static_cast<double>(literal);
}

void Literal::convert(int literal)
{
	if (literal >= MIN_CHAR && literal <= MAX_CHAR)
		this->_char = static_cast<char>(literal);
	this->_float = static_cast<float>(literal);
	this->_double = static_cast<double>(literal);
}

void Literal::convert(float literal)
{
	if (literal >= MIN_CHAR && literal <= MAX_CHAR)
		this->_char = static_cast<char>(literal);
	if (literal >= MIN_INT && literal <= MAX_INT)
		this->_int = static_cast<int>(literal);
	this->_double = static_cast<double>(literal);
}

void Literal::convert(double literal)
{
	if (literal >= MIN_CHAR && literal <= MAX_CHAR)
		this->_char = static_cast<char>(literal);
	if (literal >= MIN_INT && literal <= MAX_INT)
		this->_int = static_cast<int>(literal);
	this->_float = static_cast<float>(literal);
}

void Literal::printValues(void)
{
	const std::string pseudoFloats[] = {"-inff", "+inff", "nanf"};
	const std::string pseudoDoubles[] = {"-inf", "+inf", "nan"};
	for (int i = 0; i < 3; i++)
	{
		if (this->_literal == pseudoFloats[i] || this->_literal == pseudoDoubles[i])
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: " << pseudoFloats[i] << std::endl;
			std::cout << "double: " << pseudoDoubles[i] << std::endl;
			return ;
		}
	}
	// Char
	std::cout << "char: ";
	if (this->_char == 0 && (this->_double >= 1.0 || this->_double <= -1.0))
		std::cout << "impossible\n";
	else if (this->_char < 32 || this->_char == 127)
		std::cout << "Non displayable\n";
	else
		std::cout << this->_char << std::endl;
	std::cout << "int: ";
	if (this->_int == 0 && (this->_double >= 1.0 || this->_double <= -1.0))
		std::cout << "impossible\n";
	else
		std::cout << this->_int << std::endl;
	std::cout << "float: " << this->_float;
	if (!(this->_float != this->_float || this->_float < MIN_FLOAT || this->_float > MAX_FLOAT))
	{
		if (this->_originalType == "int" || this->_originalType == "char")
			std::cout << ".0";
		else if (this->_float > 0.0f && !(this->_float - (static_cast<int>(this->_float)) > 0.0f))
			std::cout << ".0";
		else if (this->_float < 0.0f && !((this->_float * -1.0f) - (static_cast<int>(this->_float)) > 0.0f))
			std::cout << ".0";
	}
	std::cout << "f\n";
	// Double
	std::cout << "double: " << this->_double;
	if (!(this->_double != this->_double || this->_double < MIN_DOUBLE || this->_double > MAX_DOUBLE))
	{
		if (this->_originalType == "int" || this->_originalType == "char")
			std::cout << ".0";
		else if (this->_double > 0.0 && !(this->_double - (static_cast<int>(this->_double)) > 0.0))
			std::cout << ".0";
		else if (this->_double < 0.0 && !((this->_double * -1.0) - (static_cast<int>(this->_double)) > 0.0))
			std::cout << ".0";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */