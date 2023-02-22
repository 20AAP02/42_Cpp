#ifndef DATA_HPP
# define DATA_HPP

# include <stdint.h>
# include <sys/types.h>
# include <string>

typedef struct data_t
{
	int school;
	std::string name;
} Data;

uintptr_t serialize(Data *ptr);

Data *deserialize(uintptr_t raw);

#endif