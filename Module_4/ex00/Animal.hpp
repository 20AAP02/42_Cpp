#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string type;

	public:

		Animal();
		Animal( Animal const & src );
		~Animal();

		Animal		&operator=( Animal const & rhs );

		std::string getType() const;
		void makeSound() const;

	private:

};

#endif /* ********************************************************** ANIMAL_H */