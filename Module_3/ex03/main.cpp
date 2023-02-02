#include <DiamondTrap.hpp>

int main()
{
	std::cout << "--------- Constructors ---------\n";
	DiamondTrap a("Joe");
	DiamondTrap b(a);
	DiamondTrap c;

	std::cout << "--------- Member Functions ---------\n";
	c.whoAmI();
	c = a;
	std::cout << "Attack damage: " << b.getAttackDmg() << std::endl;
	std::cout << "Energy points: " << b.getEnergyPts() << std::endl;
	std::cout << "Hit points: " << b.getHitPts() << std::endl;
	a.attack(a.getName());
	a.whoAmI();
	b.whoAmI();
	c.whoAmI();
	std::cout << "--------- Deconstructors ---------\n";
	return 0;
}