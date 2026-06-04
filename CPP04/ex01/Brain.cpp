#include "./Brain.hpp"

Brain::Brain() : count(0), max(100) { 
	std::cout << "Const : Brain generated" << std::endl;
	ideas = new std::string[max];
}
Brain::Brain(const Brain& other) : count(other.count), max(other.max) {
	ideas = new std::string[max];

	for (int i = 0; i < max; i++)
		ideas[i] = other.ideas[i];
}
Brain::~Brain() { 
	std::cout << "Dest  : Brain rotten" << std::endl;
	delete[] ideas;
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		delete[] ideas;

		max = other.max;
		count = other.count;

		ideas = new std::string[max];

		for (int i = 0; i < max; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

std::string	Brain::getIdea(int index) const { 
	if (index < 0 || index >= count)
		return "";
	return ideas[index];
}
void		Brain::setIdea(std::string idea) {
	if (count == max) {
		std::cout << "I can't hold more ideas in my mind." << std::endl;
		return;
	}

	ideas[count++] = idea;
}