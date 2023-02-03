#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <Brain.hpp>

class Animal
{
	protected:
		std::string type;

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal		&operator=( Animal const & rhs );

		std::string getType() const;
		virtual void makeSound() const;

		virtual std::string getIdea(unsigned int i) const = 0;
		virtual void setIdea(unsigned int i, std::string idea);

	private:

};

#endif /* ********************************************************** ANIMAL_H */