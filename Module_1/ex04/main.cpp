#include <fileReplace.hpp>

int main(int argc, char **argv)
{
	std::string text;
	std::string newText;

	text = inputCheck(argc, argv);
	if (text.empty())
		return 1;
	newText += replaceStrings(text, argv[2], argv[3]);
	passStringToFile(newText, argv[1]);
	return 0;
}
