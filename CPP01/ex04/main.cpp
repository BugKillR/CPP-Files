#include "Program.hpp"

static std::string replace(std::string line,
	const std::string search,
	const std::string replace)
{
	std::string	newLine = "";
	size_t		currentPos = 0;
	size_t		index = 0;

	while ((index = line.find(search, currentPos)) != std::string::npos)
	{
		newLine += line.substr(currentPos, index - currentPos);
		newLine += replace;
		currentPos = index + search.length();
	}

	newLine += line.substr(currentPos);

	return newLine;
}

int	main(int argc, char *argv[])
{
	std::string	filename;
	std::string	s1;
	std::string	s2;
	std::string	line;
	std::string	filtered;
	std::string	outputName;
	size_t		pos;

	if (argc != 4)
		return (1);

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];

	if (s1.empty())
		return (1);

	pos = filename.find_last_of("/");

	if (pos != std::string::npos)
		outputName = filename.substr(pos + 1);
	else
		outputName = filename;

	std::ifstream	file(filename.c_str());
	std::ofstream	newFile((outputName + ".replace").c_str());

	if (!file.is_open())
		return (std::cout << "Unable to open file!" << std::endl, 1);

	while (std::getline(file, line))
	{
		filtered = replace(line, s1, s2);
		newFile << filtered << std::endl;
	}

	return (0);
}