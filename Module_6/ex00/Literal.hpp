#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <sstream>

# define MAX_CHAR 255.0
# define MIN_CHAR 0.0
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# define MAX_FLOAT 3.40282e+038
# define MIN_FLOAT -3.40282e+038
# define MAX_DOUBLE 1.79769e+308
# define MIN_DOUBLE -1.79769e+308

class Literal
{

	public:
		Literal(const std::string literal);
		Literal( Literal const & src );
		~Literal();

		Literal &		operator=( Literal const & rhs );

		std::string _literal;
		std::string _originalType;
		char _char;
		int _int;
		float _float;
		double _double;

		std::string convertToOriginalType(const std::string literal);
		void convert(char literal);
		void convert(int literal);
		void convert(float literal);
		void convert(double literal);
		void printValues(void);


	private:
		Literal();
		std::string getType(const std::string arg) const;


};

std::ostream &			operator<<( std::ostream & o, Literal const & i );

#endif /* ********************************************************* LITERAL_H */