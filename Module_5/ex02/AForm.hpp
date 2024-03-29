#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <Bureaucrat.hpp>

class Bureaucrat;

class AForm
{

	public:

		AForm(const std::string name, const int gradeSgn, const int gradeExc);
		AForm( AForm const & src );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		std::string getName() const;
		bool isSigned() const;
		int getRqdGradeToSgn() const;
		int getRqdGradeToExc() const;

		void beSigned(Bureaucrat const &bureaucrat);

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

		class NotSignedException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Form hasn't been signed!");
				}
		};

		class GradeTooLowToExecuteException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Bureaucrat's grade is too low to execute this form!");
				}
		};

		void execute(Bureaucrat const &executor) const;
		virtual void action() const = 0;

	private:
		AForm();
		const std::string name;
		bool _signed;
		const int _rqdGradeToSgn;
		const int _rqdGradeToExc;
		void testGrade(int grade) const;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AFORM_H */