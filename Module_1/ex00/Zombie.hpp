#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <cctype>
# include <string>
# include <bits/stdc++.h>
# include <unistd.h>

class Zombie
{
public:
	void announce(void);
	Zombie(std::string name);
	~Zombie(void);
private:
	std::string name;
	Zombie(void);
};

#endif