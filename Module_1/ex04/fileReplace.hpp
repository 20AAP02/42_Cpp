#ifndef FILEREPLACE_HPP
# define FILEREPLACE_HPP

# include <iostream>
# include <fstream>
# include <string.h>

std::string convertFileName(std::string filename);

std::string copyFileToString(std::string filename);

std::string inputCheck(int argc, char **argv);

std::string replaceStrings(std::string text, std::string s1, std::string s2);

void passStringToFile(std::string str, std::string filename);

#endif