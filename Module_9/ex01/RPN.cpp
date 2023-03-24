#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	this->expression = src.expression;
	this->polishMathExpression = src.polishMathExpression;
}

RPN::RPN(const std::string expression)
{
	this->expression = expression;
	std::stringstream str(expression);
	std::string element;
	while (getline(str, element, ' '))
	{
		element.erase(std::remove_if(element.begin(), element.end(), ::isspace), element.end());
		if (this->elementIsValid(element))
		{
			if (isdigit(element[0]))
				this->polishMathExpression.push(atoi(element.c_str()));
			else
			{
				if (this->polishMathExpression.size() < 2)
				{
					std::cout << "Error\n";
					return;
				}
				int x, y;
				x = this->polishMathExpression.top();
				this->polishMathExpression.pop();
				y = this->polishMathExpression.top();
				this->polishMathExpression.pop();
				this->polishMathExpression.push(this->calcOperation(element[0], y, x));
			}
		}
		else
		{
			std::cout << "Error\n";
			return;
		}
	}
	if (this->polishMathExpression.size() > 1)
	{
		std::cout << "Error\n";
		return;
	}
	std::cout << this->polishMathExpression.top() << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	if ( this != &rhs )
	{
		this->expression = rhs.expression;
		this->polishMathExpression = rhs.polishMathExpression;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RPN const & i )
{
	o << "Value = " << i.getExpression();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

int RPN::elementIsValid(const std::string elm) const
{
	if ((int)elm.size() != 1)
		return 0;
	for (char a = '0'; a <= '9'; a++)
	{
		if (elm[0] == a)
			break;
		if (a == '9' && elm[0] != '+' && elm[0] != '-' && elm[0] != '/' && elm[0] != '*')
			return 0;
	}
	return 1;
}

int RPN::calcOperation(char optr, int x, int y) const
{
	switch (optr)
	{
		case '+':
			return x + y;
		case '-':
			return x - y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		
		default:
			return x + y;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string RPN::getExpression() const
{
	return this->expression;
}


/* ************************************************************************** */