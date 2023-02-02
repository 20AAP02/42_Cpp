#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <ClapTrap.hpp>
# include <iostream>
# include <string>

class FragTrap: virtual public ClapTrap
{

	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();

		void operator =(FragTrap const & rhs);

		void highFivesGuys(void);

	private:

};

#endif /* ******************************************************** SCAVTRAP_H */