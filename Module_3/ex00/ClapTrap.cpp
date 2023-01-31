#include <ClapTrap.hpp>

ClapTrap::ClapTrap()
{
	this->name = "Unkown";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

void ClapTrap::operator =(const ClapTrap &c)
{
	
}

ClapTrap::~ClapTrap()
{
	
}


void ClapTrap::attack(const std::string &target)
{
	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	
}
