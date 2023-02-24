#include "ScalarConverter.hpp"

std::string ScalarConverter::_literal;
std::string ScalarConverter::_originalType;
char ScalarConverter::_char;
int ScalarConverter::_int;
float ScalarConverter::_float;
double ScalarConverter::_double;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
	this->_char = 0;
	this->_int = 0;
	this->_float = 0;
	this->_double = 0;
}

ScalarConverter::ScalarConverter(const std::string literal)
{
	this->_literal = literal;
	this->_char = 0;
	this->_int = 0;
	this->_float = 0;
	this->_double = 0;
	this->convert(literal);
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
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

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
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

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i )
{
	o << i._literal;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ScalarConverter::convert(std::string literal)
{
	_originalType = convertToOriginalType(literal);
	if (_originalType == "char")
		convert(_char);
	else if (_originalType == "int")
		convert(_int);
	else if (_originalType == "float" || _originalType == "floatP")
		convert(_float);
	else if (_originalType == "double" || _originalType == "doubleP")
		convert(_double);
}

std::string ScalarConverter::getType(const std::string arg)
{
	const std::string pseudoFloats[] = {"-inff", "+inff", "nanf"};
	const std::string pseudoDoubles[] = {"-inf", "+inf", "nan"};
	if (std::isdigit(arg[0]) || (arg.length() > 1 && std::isdigit(arg[1]) && arg[0] == '-'))
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

std::string ScalarConverter::convertToOriginalType(const std::string literal)
{
	std::string type = getType(literal);

	if (type == "char")
		_char = literal[0];
	else if (type == "int")
		_int = atoi(literal.c_str());
	else if (type == "float" || type == "floatP")
		_float = static_cast<float>(atof(literal.c_str()));
	else if (type == "double" || type == "doubleP")
		_double = atof(literal.c_str());
	return type;
}

void ScalarConverter::convert(char literal)
{
	_int = static_cast<int>(literal);
	_float = static_cast<float>(literal);
	_double = static_cast<double>(literal);
}

void ScalarConverter::convert(int literal)
{
	if (literal >= MIN_CHAR && literal <= MAX_CHAR)
		_char = static_cast<char>(literal);
	_float = static_cast<float>(literal);
	_double = static_cast<double>(literal);
}

void ScalarConverter::convert(float literal)
{
	if (literal >= MIN_CHAR && literal <= MAX_CHAR)
		_char = static_cast<char>(literal);
	if (literal >= MIN_INT && literal <= MAX_INT)
		_int = static_cast<int>(literal);
	_double = static_cast<double>(literal);
}

void ScalarConverter::convert(double literal)
{
	if (literal >= MIN_CHAR && literal <= MAX_CHAR)
		_char = static_cast<char>(literal);
	if (literal >= MIN_INT && literal <= MAX_INT)
		_int = static_cast<int>(literal);
	_float = static_cast<float>(literal);
}

void ScalarConverter::printValues(void)
{
	const std::string pseudoFloats[] = {"-inff", "+inff", "nanf"};
	const std::string pseudoDoubles[] = {"-inf", "+inf", "nan"};
	for (int i = 0; i < 3; i++)
	{
		if (_literal == pseudoFloats[i] || _literal == pseudoDoubles[i])
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
	if (_char == 0 && (_double >= 1.0 || _double <= -1.0))
		std::cout << "impossible\n";
	else if (_char < 32 || _char == 127)
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << _char << "'" << std::endl;
	std::cout << "int: ";
	if (_int == 0 && (_double >= 1.0 || _double <= -1.0))
		std::cout << "impossible\n";
	else
		std::cout << _int << std::endl;
	std::cout << "float: " << _float;
	if (!(_float != _float || _float < MIN_FLOAT || _float > MAX_FLOAT))
	{
		if (_originalType == "int" || _originalType == "char")
			std::cout << ".0";
		else if (_float > 0.0f && !(_float - (static_cast<int>(_float)) > 0.0f))
			std::cout << ".0";
		else if (_float < 0.0f && !((_float * -1.0f) - (static_cast<int>(_float)) > 0.0f))
			std::cout << ".0";
	}
	std::cout << "f\n";
	// Double
	std::cout << "double: " << _double;
	if (!(_double != _double || _double < MIN_DOUBLE || _double > MAX_DOUBLE))
	{
		if (_originalType == "int" || _originalType == "char")
			std::cout << ".0";
		else if (_double > 0.0 && !(_double - (static_cast<int>(_double)) > 0.0))
			std::cout << ".0";
		else if (_double < 0.0 && !((_double * -1.0) - (static_cast<int>(_double)) > 0.0))
			std::cout << ".0";
	}
	std::cout << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */