#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
public:
	void announce(void);
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void nameIt(std::string name);
private:
	std::string name;
};


void randomChump(std::string name);

Zombie *newZombie(std::string name);

Zombie* zombieHorde(int N, std::string name);

#endif