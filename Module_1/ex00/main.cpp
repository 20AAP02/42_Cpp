#include <Zombie.hpp>

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main()
{
	randomChump("Jonhy");
	Zombie *z = newZombie("Jorge");
	z->announce();
	delete z;
	return 0;
}