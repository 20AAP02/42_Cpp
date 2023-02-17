#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <AForm.hpp>

class ShrubberyCreationForm: public AForm
{

	public:
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

		std::string getTarget() const;

		void execute(Bureaucrat const &executor) const;
		void func() const;

	private:
		ShrubberyCreationForm();
		std::string _target;

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */