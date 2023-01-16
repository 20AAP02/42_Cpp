#include <fileReplace.hpp>

std::fstream newFile(std::string filename)
{
	std::fstream file;

	file.open(filename, std::ios::out);
	if (!file)
}