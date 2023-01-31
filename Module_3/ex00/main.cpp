#include <ClapTrap.hpp>

int main()
{
	ClapTrap a("Joe");
	ClapTrap b("Richard");
	ClapTrap c("Elizabeth");
	ClapTrap x;
	ClapTrap l(c);
	
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	c.takeDamage(50);
	x = a;
	x.attack(c.getName());
	return 0;
}