#include <ClapTrap.hpp>

ClapTrap::ClapTrap()
{
	this->name = "Unkown";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << this->name << " was created by default constructor!\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	std::cout << "ClapTrap " << this->name << " was created by constructor with name!\n";
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	this->name = c.getName();
	this->hitPoints = c.getHitPts();
	this->energyPoints = c.getEnergyPts();
	this->attackDamage = c.getAttackDmg();
	std::cout << "ClapTrap " << this->name << " was created by copy constructor!\n";
}

void ClapTrap::operator =(const ClapTrap &c)
{
	this->name = c.getName();
	this->hitPoints = c.getHitPts();
	this->energyPoints = c.getEnergyPts();
	this->attackDamage = c.getAttackDmg();
	std::cout << "ClapTrap " << this->name << " called copy assigment operator\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " has been destroyed :(\n";
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " has no energy to attack...\n";
		return ;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > (int)amount)
	{
		std::cout << "ClapTrap " << this->name << " is being attacked, losing " << amount << " hit points!\n";
		this->hitPoints -= (int)amount;
	}
	else if (this->hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->name << " has been dead a while ago...\n";
	}
	else
	{
		this->energyPoints = 0;
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " has died...\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		this->hitPoints += (int)amount;
		std::cout << "ClapTrap " << this->name << " is reparing itself, gaining " << amount << " hit points\n";
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " has no energy to repair itself...\n";
		return ;
	}
}

std::string ClapTrap::getName() const {	return this->name; }

int ClapTrap::getHitPts() const { return this->hitPoints; }

int ClapTrap::getEnergyPts() const { return this->energyPoints; }

int ClapTrap::getAttackDmg() const { return this->attackDamage; }
