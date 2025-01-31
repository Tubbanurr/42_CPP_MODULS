#include "Replace.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace <filename> s1 s2" << std::endl;
		return (1);
	}
	Replace* replace = new Replace();

	replace->fileName = av[1];
	replace->s1 = av[2];
	replace->s2 = av[3];

	if (!replaceInFile(replace->fileName, replace->s1, replace->s2))
	{
		delete replace;
		return (1);
	}
	delete replace;

	return (0);
}
