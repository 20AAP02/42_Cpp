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
		
		void execute(Bureaucrat const &executor) const;
		virtual void func() const = 0;

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