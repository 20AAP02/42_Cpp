#include <ScavTrap.hpp>

int main()
{
	std::cout << "----- Constructors -----\n";
	ScavTrap a("Joe");
	ScavTrap b("Richard");
	ScavTrap c("Elizabeth");
	ScavTrap x;
	ScavTrap l(c);
	
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
	std::cout << "\n----- Deconstructors -----\n";
	return 0;
}
