#include "Replace.hpp"

Replace::Replace(){}

bool replaceInFile(const std::string &fileName, const std::string &s1, const std::string &s2)
{
	if (s1.empty() || s2.empty())
	{
		std::cerr << "Error: s1 and s2 must not be empty" << std::endl;
		return (false);
	}
	if (s1 == s2)
	{
		std::cerr << "Error: s1 and s2 must be different" << std::endl;
		return (false);
	}

	std::ifstream	inputFile(fileName.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return (false);
	}

	std::string		outputFileName = fileName + ".replace";
	std::ofstream	outputFile(outputFileName.c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: could not create output file" << std::endl;
		return (false);
	}

	std::string	line;
	while (std::getline(inputFile, line))
	{
        std::string::size_type pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
		{
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outputFile << line << std::endl;
    }

	inputFile.close();
	outputFile.close();
	return (true);
}

