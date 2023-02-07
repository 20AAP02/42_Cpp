#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <Brain.hpp>

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal( Animal const & src );

	public:

		virtual ~Animal();

		Animal		&operator=( Animal const & rhs );

		std::string getType() const;
		virtual void makeSound() const = 0;

	private:

};

#endif /* ********************************************************** ANIMAL_H */