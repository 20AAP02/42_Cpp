#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <Bureaucrat.hpp>

class Form
{

	public:

		Form(const std::string name, const int requiredGradeToSign, int requiredGradeToExecute);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string getName() const;
		bool isSigned() const;
		int getRequiredGradeToSign() const;
		int getRequiredGradeToExecute() const;

		void beSigned(Bureaucrat bureaucrat);

	private:
		Form();
		const std::string name;
		bool _signed;
		const int requiredGradeToSign;
		const int requiredGradeToExecute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */