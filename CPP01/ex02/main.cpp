#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Adress of string     :" << &str << std::endl;
	std::cout << "Adress of pointer    :" << stringPTR << std::endl;
	std::cout << "Adress of reference  :" << &stringREF << std::endl;
 
	std::cout << std::endl; 
 
	std::cout << "Value of string      :" << str << std::endl;
	std::cout << "Value pointed by ptr :" << *stringPTR << std::endl;
	std::cout << "Value pointed by ref :" << stringREF << std::endl;

	return (0);
}
