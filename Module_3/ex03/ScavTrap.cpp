#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " was created by default constructor!\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " was created by constructor with name!\n";
}

ScavTrap::ScavTrap( const ScavTrap & src ): ClapTrap(src)
{
	this->name = src.getName();
	this->hitPoints = src.getHitPts();
	this->energyPoints = src.getEnergyPts();
	this->attackDamage = src.getAttackDmg();
	std::cout << "ScavTrap " << this->name << " was created by copy constructor!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " has been destroyed :(\n";
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
		std::cout << "ScavTrap " << this->name << " called copy assigment operator\n";
	}
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " has no energy to attack...\n";
		return ;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */