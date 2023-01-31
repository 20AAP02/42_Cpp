#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
	ClapTrap();

public:
	ClapTrap(const ClapTrap &c);
	ClapTrap(std::string name);
	ClapTrap operator =(const ClapTrap &c);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void message(const std::string &target, const std::string type, unsigned int amount) const;
	std::string getName();
	int getHitPts() const;
	int getEnergyPts() const;
	int getAttackDmg() const;
};


#endif