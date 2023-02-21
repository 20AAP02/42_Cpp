#ifndef LITERAL_HPP
# define LITERAL_HPP

# include <iostream>
# include <string>

class Literal
{

	public:
		Literal(const std::string literal);
		Literal( Literal const & src );
		~Literal();

		Literal &		operator=( Literal const & rhs );

		std::string _literal;
		char _char;
		int _int;
		float _float;
		double _double;

	private:
		Literal();
		std::string getType(const std::string arg) const;


};

std::ostream &			operator<<( std::ostream & o, Literal const & i );

#endif /* ********************************************************* LITERAL_H */