#include "./PhoneBook.hpp"

int	main(void) {
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << "###########################################" << std::endl;
	std::cout << "#           Welcome to kkeskin's          #" << std::endl;
	std::cout << "#                                         #" << std::endl;
	std::cout << "# _____ _               _____         _   #" << std::endl;
	std::cout << "#|  _  | |_ ___ ___ ___| __  |___ ___| |_ #" << std::endl;
	std::cout << "#|   __|   | . |   | -_| __ -| . | . | '_|#" << std::endl;
	std::cout << "#|__|  |_|_|___|_|_|___|_____|___|___|_,_|#" << std::endl;
	std::cout << "#                                         #" << std::endl;
	std::cout << "#       Commands: ADD, SEARCH, EXIT.      #" << std::endl;
	std::cout << "###########################################" << std::endl;

	while (1)
	{
		std::cout << "Command:          ";
		getline(std::cin, input);
		std::cout << std::endl;
		if (input == "ADD")
		{
			if (!phoneBook.add())
				break;
		}
		else if (input == "SEARCH")
		{
			if (!phoneBook.search())
				break;
		}
		else if (input == "EXIT")
			break ;
		else if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			break ;
		}
		else
			std::cout << "Warning:          Command is not valid!" << std::endl;
		std::cout << std::endl;
	}
	return (0);
}
