#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include <Animal.hpp>
# include <Brain.hpp>

class Dog: public Animal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		Dog &		operator=( Dog const & rhs );
		void makeSound() const;

		std::string getIdea(unsigned int i) const;
		void setIdea(unsigned int i, std::string idea);

	private:
		Brain *brain;

};

#endif /* ************************************************************* DOG_H */