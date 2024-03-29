#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <Form.hpp>

class Form;

class Bureaucrat
{

	public:

		Bureaucrat(const std::string name, const int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();

		void signForm(Form &form) const;

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
		Bureaucrat();
		const std::string name;
		int grade;
		void testGrade(int grade) const;
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */