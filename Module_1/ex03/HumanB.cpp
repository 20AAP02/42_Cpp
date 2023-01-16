#include <HumanB.hpp>

HumanB::~HumanB(void)
{
}

void HumanB::attack(void)
{
	std::cout << HumanB::name << " attacks with their " << HumanB::weapon->getType();
	std::cout << std::endl;
}

HumanB::HumanB(std::string name)
{
	HumanB::name = name;
}

void HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}