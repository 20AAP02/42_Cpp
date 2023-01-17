#include <fileReplace.hpp>

std::string copyFileToString(std::string filename)
{
	char ch;
	std::fstream file;
	std::string fileInStr;

	file.open(filename.c_str(), std::ios::in);
	if (!file)
	{
		std::cout << "Failed to open file\n";
		return std::string();
	}
	ch = file.get();
	while (file)
	{
		fileInStr += ch;
		ch = file.get();
	}
	file.close();
	return fileInStr;
}

std::string convertFileName(std::string filename)
{
	std::string newFileName;

	newFileName = filename + ".replace";
	return newFileName;
}

std::string inputCheck(int argc, char **argv)
{
	std::string oldFileInString;

	if (argc != 4)
		return std::string();
	return copyFileToString(argv[1]);
}

std::string replaceStrings(std::string text, std::string s1, std::string s2)
{
	std::string outputText;
	int index = 0;

	size_t found = text.find(s1);
	while (found != std::string::npos)
	{
		outputText += text.substr(index, found - index);
		outputText += s2;
		index = found + s1.length();
		found = text.find(s1, index);
	}
	outputText += text.substr(index, text.length() - index);
	return outputText;
}

void passStringToFile(std::string str, std::string filename)
{
	std::fstream file;

	file.open(convertFileName(filename).c_str(), std::ios::out);
	if (!file)
	{
		std::cout << "Failed to create file\n";
		return ;
	}
	file.write(str.c_str(), str.length());
	file.close();

}
