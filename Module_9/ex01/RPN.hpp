#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <stack>
# include <fstream>
# include <sstream>


class RPN
{

	public:

		RPN( RPN const & src );
		RPN(const std::string expression);
		~RPN();

		RPN &		operator=( RPN const & rhs );

		std::string getExpression() const;

	private:
		std::stack<int> polishMathExpression;
		std::string expression;
		
		int elementIsValid(const std::string elm) const;
		int calcOperation(char optr, int x, int y) const;

		RPN();

};

std::ostream &			operator<<( std::ostream & o, RPN const & i );

#endif /* ************************************************************* RPN_H */