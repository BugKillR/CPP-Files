#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"

class PhoneBook {
private:
	Contact _contact[8];
	int		_count;
	int		_maxLength;
public:
	PhoneBook();
	bool	add();
	bool	search();
};

#endif