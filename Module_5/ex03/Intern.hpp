#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include <AForm.hpp>
# include <PresidentialPardonForm.hpp>
# include <RobotomyRequestForm.hpp>
# include <ShrubberyCreationForm.hpp>

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm *makeForm(const std::string formName, const std::string formTarget) const;
	
	private:

};

#endif /* ********************************************************** INTERN_H */