#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include <FragTrap.hpp>
# include <ScavTrap.hpp>

class DiamondTrap: public ScavTrap, public FragTrap
{

	public:

		DiamondTrap();
		DiamondTrap( std::string name );
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();

		void operator=( DiamondTrap const & rhs );
		void whoAmI();

	private:
		std::string name;
		using FragTrap::hitPoints;
		using ScavTrap::energyPoints;
		using FragTrap::attackDamage;

};

#endif /* ***************************************************** DIAMONDTRAP_H */