#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <AForm.hpp>

class RobotomyRequestForm: public AForm
{

	public:
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		std::string getTarget() const;
	
		void execute(Bureaucrat const &executor) const;
		void action() const;

	private:
		RobotomyRequestForm();
		std::string _target;

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */