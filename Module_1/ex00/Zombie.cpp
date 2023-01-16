#include <Zombie.hpp>

void Zombie::announce(void)
{
	std::cout << Zombie::name << " : BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
}

Zombie::~Zombie(void)
{
	std::cout << Zombie::name << " died...\n";
}
