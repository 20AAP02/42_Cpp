#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <Bureaucrat.hpp>

class Form
{

	public:

		Form(const std::string name, const int gradeSgn, const int gradeExc);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string getName() const;
		bool isSigned() const;
		int getRqdGradeToSgn() const;
		int getRqdGradeToExc() const;

		void beSigned(Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high!");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too low!");
				}
		};

	private:
		Form();
		const std::string name;
		bool _signed;
		const int _rqdGradeToSgn;
		const int _rqdGradeToExc;
		void testGrade(int grade) const;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */