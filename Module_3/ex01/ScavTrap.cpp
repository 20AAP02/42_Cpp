#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->message("ScavTrap", "Unknown", "CREATED", 0);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->message("ScavTrap", "Unknown", "CREATEDN", 0);
}

ScavTrap::ScavTrap( const ScavTrap & src ): ClapTrap(src)
{
	this->name = src.getName();
	this->hitPoints = src.getHitPts();
	this->energyPoints = src.getEnergyPts();
	this->attackDamage = src.getAttackDmg();
	this->message("ScavTrap", "Unknown", "CREATEDC", 0);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	this->message("ScavTrap", "Unknown", "DESTROYED", 0);
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

void ScavTrap::operator=( ScavTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		this->hitPoints = rhs.getHitPts();
		this->energyPoints = rhs.getEnergyPts();
		this->attackDamage = rhs.getAttackDmg();
	}
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap: " << this->name << " is now in Gate keeper mode\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */