#include <HumanA.hpp>

HumanA::~HumanA(void)
{
}

void HumanA::attack(void)
{
	std::cout << HumanA::name << " attacks with their " << HumanA::weapon->getType();
	std::cout << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon)
{
	HumanA::name = name;
	HumanA::weapon = &weapon;
}