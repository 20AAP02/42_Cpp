#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	this->name = "Unkown";
	this->ClapTrap::name += "_clap_name";
	this->energyPoints = this->ScavTrap::energyPoints;
	std::cout << "DiamondTrap " << this->name << " was created by default constructor!\n";

}

DiamondTrap::DiamondTrap( std::string name ): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->name = name;
	this->energyPoints = this->ScavTrap::energyPoints;
	std::cout << "DiamondTrap " << this->name << " was created by constructor with name!\n";
}

DiamondTrap::DiamondTrap( const DiamondTrap & src ): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	this->name = src.name;
	std::cout << "DiamondTrap " << this->name << " was created by copy constructor!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " has been destroyed :(\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

void				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.name;
		this->ClapTrap::name = rhs.ClapTrap::getName();
		this->hitPoints = rhs.getHitPts();
		this->energyPoints = rhs.getEnergyPts();
		this->attackDamage = rhs.getAttackDmg();
		std::cout << "DiamondTrap " << this->name << " called copy assigment operator\n";
	}
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void DiamondTrap::whoAmI()
{
	std::cout << "Hi! My name is 🎶 What?\n";
	std::cout << "ClapTrap name: " << this->ClapTrap::name << std::endl;
	std::cout << "DiamondTrap name: " << this->name << std::endl;

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */