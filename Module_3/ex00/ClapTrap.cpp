#include <ClapTrap.hpp>

ClapTrap::ClapTrap()
{
	this->name = "Unkown";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	this->message("ClapTrap", "Unknown", "CREATED", 0);
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
	this->message("ClapTrap", "Unknown", "CREATEDN", 0);
}

ClapTrap::ClapTrap(const ClapTrap &c)
{
	this->name = c.getName();
	this->hitPoints = c.getHitPts();
	this->energyPoints = c.getEnergyPts();
	this->attackDamage = c.getAttackDmg();
	this->message("ClapTrap", "Unknown", "CREATEDC", 0);
}

void ClapTrap::operator =(const ClapTrap &c)
{
	this->name = c.getName();
	this->hitPoints = c.getHitPts();
	this->energyPoints = c.getEnergyPts();
	this->attackDamage = c.getAttackDmg();
	this->message("ClapTrap", "Unknown", "COPYOPERATER", 0);
}

ClapTrap::~ClapTrap()
{
	this->message("ClapTrap", "Unknown", "DESTROYED", 0);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		this->message("ClapTrap", target, "ATTACK", 0);
	}
	else
	{
		this->message("ClapTrap", target, "NOENERGY_ATTACK", 0);
		return ;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > (int)amount)
	{
		this->message("ClapTrap", "Unknown", "DAMAGE", amount);
		this->hitPoints -= (int)amount;
	}
	else if (this->hitPoints == 0)
	{
		this->message("ClapTrap", "Unknown", "ALREADYDEAD", amount);
	}
	else
	{
		this->energyPoints = 0;
		this->hitPoints = 0;
		this->message("ClapTrap", "Unknown", "DIED", amount);
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		this->message("ClapTrap", "Unkown", "REPAIR", amount);
		this->hitPoints += (int)amount;
	}
	else
	{
		this->message("ClapTrap", "Unkwon", "NOENERGY_REPAIR", amount);
		return ;
	}
}

void ClapTrap::message("ClapTrap", const std::string &target, const std::string type, unsigned int amount) const
{
	std::cout << "ClapTrap " << this->name;
	if (type == "ATTACK")
		std::cout << " attacks " << target << ", causing " << this->attackDamage << " points of damage!\n";
	else if (type == "REPAIR")
		std::cout << " is reparing itself, gaining " << amount << " hit points\n";
	else if (type == "DAMAGE")
		std::cout << " is being attacked, losing " << amount << " hit points!\n";
	else if (type == "DIED")
		std::cout << " has died...\n";	
	else if (type == "NOENERGY_REPAIR")
		std::cout << " has no energy to repair itself...\n";
	else if (type == "NOENERGY_ATTACK")
		std::cout << " has no energy to attack...\n";
	else if (type == "CREATED")
		std::cout << " was created by default constructor!\n";
	else if (type == "CREATEDN")
		std::cout << " was created by constructor with name!\n";
	else if (type == "CREATEDC")
		std::cout << " was created by copy constructor!\n";
	else if (type == "DESTROYED")
		std::cout << " has been DESTROYED :(\n";
	else if (type == "ALREADYDEAD")
		std::cout << " has been dead a while ago...\n";
	else if (type == "COPYOPERATER")
		std::cout << " called copy assigment operator\n";
}

std::string ClapTrap::getName() const {	return this->name; }

int ClapTrap::getHitPts() const { return this->hitPoints; }

int ClapTrap::getEnergyPts() const { return this->energyPoints; }

int ClapTrap::getAttackDmg() const { return this->attackDamage; }
