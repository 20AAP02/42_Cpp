#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string getName() const;
		int getGrade() const;
		void increment();
		void decrement();

	private:
		const std::string name;
		int grade;
};

#endif /* ****************************************************** BUREAUCRAT_H */