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

class Serializer
{
	public:
		Serializer();
		Serializer( Serializer const & src );
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);

	private:

};

#endif