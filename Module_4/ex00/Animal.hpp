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

		void		operator=( Animal const & rhs );
		void setType(std::string type);
		std::string getType() const;

	private:

};

#endif /* ********************************************************** ANIMAL_H */