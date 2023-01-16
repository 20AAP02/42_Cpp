#include <Weapon.hpp>

const std::string &Weapon::getType(void)
{
	return Weapon::type;
}

void Weapon::setType(std::string type)
{
	Weapon::type = type;
}

Weapon::~Weapon(void)
{
}

Weapon::Weapon(void)
{
	Weapon::setType("non-existent weapon");
}

Weapon::Weapon(std::string type)
{
	Weapon::type = type;
}