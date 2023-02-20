#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include <AForm.hpp>

class PresidentialPardonForm: public AForm
{

	public:
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

		std::string getTarget() const;
	
		void execute(Bureaucrat const &executor) const;
		void action() const;

	private:
		PresidentialPardonForm();
		std::string _target;

};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */