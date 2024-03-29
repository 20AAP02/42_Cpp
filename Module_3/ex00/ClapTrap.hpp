#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap &c);
	ClapTrap(std::string name);
	void operator =(const ClapTrap &c);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	int getHitPts() const;
	int getEnergyPts() const;
	int getAttackDmg() const;
};

#endif