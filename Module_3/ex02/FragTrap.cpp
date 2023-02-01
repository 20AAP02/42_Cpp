#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " was created by default constructor!\n";
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " was created by constructor with name!\n";
}

FragTrap::FragTrap( const FragTrap & src ): ClapTrap(src)
{
	this->name = src.getName();
	this->hitPoints = src.getHitPts();
	this->energyPoints = src.getEnergyPts();
	this->attackDamage = src.getAttackDmg();
	std::cout << "FragTrap " << this->name << " was created by copy constructor!\n";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " has been destroyed :(\n";
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

void FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		this->hitPoints = rhs.getHitPts();
		this->energyPoints = rhs.getEnergyPts();
		this->attackDamage = rhs.getAttackDmg();
		std::cout << "FragTrap " << this->name << " called copy assigment operator\n";
	}
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << ", hight five?\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */