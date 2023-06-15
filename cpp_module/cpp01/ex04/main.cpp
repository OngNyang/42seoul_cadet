#include "sed.hpp"

std::string	replace_string(const std::string& original, const std::string& s1, const std::string& s2)
{
	std::string	result = original;
	size_t		pos = 0;

	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		pos += s2.length();
	}
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error: wrong argument" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::ifstream	inputFile(filename);
	if (!inputFile)
	{
		std::cout << "Error: opening input file" << std::endl;
		return (1);
	}

	std::ofstream	outputFile(filename + ".replace");
	if (!outputFile)
	{
		std::cout << "Error: creating output file" << std::endl;
		return (1);
	}

	std::string	line;
	std::string	replaced_line;
	while (std::getline(inputFile, line))
	{
		replaced_line = replace_string(line, s1, s2);
		outputFile << replaced_line << std::endl;
	}

	inputFile.close();
	outputFile.close();

	return (0);
}