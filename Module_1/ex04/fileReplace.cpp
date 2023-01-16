#include <fileReplace.hpp>

std::fstream openFile(std::string filename, std::ios_base::openmode __mode)
{
	std::fstream file;

	file.open(filename, __mode);
	if (!file)
		std::cout << "Failed to open or create file\n";
	return file;
}

std::string convertFileName(std::string filename)
{
	std::string newFileName;

	newFileName = filename + ".replace";
	return newFileName;
}

std::string nextString(std::fstream file)
{
	std::string nextStr;
	char ch;
	while (file)
	{
		ch = file.get();
	}
}

std::string copyFileToString(std::string fileName)
{
	std::fstream oldFile = openFile(fileName, std::ios::in);
	if (!oldFile)
		return NULL;
	std::string fileInStr;
	char ch;
	while (oldFile)
	{
		ch = oldFile.get();
		fileInStr += ch;
	}
	oldFile.close();
	return fileInStr;
}