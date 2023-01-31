#include <ClapTrap.hpp>

int main()
{
	ClapTrap a("Joe");
	ClapTrap b("Richard");
	ClapTrap c("Elizabeth");
	
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	c.takeDamage(50);
	return 0;
}