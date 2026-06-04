#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {
private:
std::string	*ideas;
int			count;
int			max;

public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	std::string	getIdea(int index) const;
	void		setIdea(std::string idea);

	Brain&	operator=(const Brain& other);

};

#endif