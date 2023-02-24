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

class ScalarConverter
{

	public:
		ScalarConverter(const std::string literal);
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();

		ScalarConverter &		operator=( ScalarConverter const & rhs );

		static std::string _literal;
		static std::string _originalType;
		static char _char;
		static int _int;
		static float _float;
		static double _double;

		static std::string convertToOriginalType(const std::string literal);
		static void convert(std::string literal);
		static void convert(char literal);
		static void convert(int literal);
		static void convert(float literal);
		static void convert(double literal);
		static void printValues(void);


	private:
		ScalarConverter();
		static std::string getType(const std::string arg);


};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ********************************************************* LITERAL_H */