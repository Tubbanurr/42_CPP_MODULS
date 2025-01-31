#ifndef 	REPLACE_HPP
# define 	REPLACE_HPP

#include <iostream>
#include <fstream>

class Replace
{
	public:
		std::string		fileName;
		std::string		s1;
		std::string		s2;
		Replace();
};
	bool replaceInFile(const std::string &fileName, const std::string &s1, const std::string &s2);

#endif
