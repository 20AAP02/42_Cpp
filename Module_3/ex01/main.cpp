#include <ClapTrap.hpp>
#include <ScavTrap.hpp>

int main()
{
	ScavTrap a("Joe");
	ScavTrap b("Richard");
	ScavTrap c("Elizabeth");
	ScavTrap x;
	ScavTrap l(c);
	
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	c.takeDamage(50);
	x = a;
	x.attack(c.getName());
	x.guardGate();
	return 0;
}