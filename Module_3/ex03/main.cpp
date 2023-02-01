#include <FragTrap.hpp>

int main()
{
	FragTrap a("Joe");
	FragTrap b("Richard");
	FragTrap c("Elizabeth");
	FragTrap x;
	FragTrap l(c);
	
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	c.takeDamage(50);
	x = a;
	x.attack(c.getName());
	x.highFivesGuys();
	return 0;
}