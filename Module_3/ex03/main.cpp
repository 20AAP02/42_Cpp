#include <DiamondTrap.hpp>

int main()
{
	std::cout << "----- Constructors -----\n";
	DiamondTrap a("Joe");
	DiamondTrap b("Richard");
	DiamondTrap c("Elizabeth");
	DiamondTrap x;
	DiamondTrap l(c);
	
	std::cout << "\n----- Points -----\n";
	std::cout << "Hit points: " << a.getHitPts() << std::endl;
	std::cout << "Energy points: " << a.getEnergyPts() << std::endl;
	std::cout << "Attack damage: " << a.getAttackDmg() << std::endl;
	std::cout << "\n----- Default functions -----\n";
	x = l;
	a.attack(x.getName());
	x.takeDamage(a.getAttackDmg());
	l.beRepaired(5);
	b.guardGate();
	b.highFivesGuys();
	c.whoAmI();
	std::cout << "\n----- Deconstructors -----\n";
	return 0;
}