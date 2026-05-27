#include "./PhoneBook.hpp"

PhoneBook::PhoneBook() : _count(0), _maxLength(8) { }

static bool	setContact(Contact& newContact, std::string msg, void (Contact::*setter)(std::string))
{
	std::string	input;

	while (1)
	{
		std::cout << msg;
		getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			return false;
		}
		else if (input == "")
		{
			std::cout << "Warning:          Empty fileds are not allowed!" << std::endl;
			continue;
		}
		else
		{
			(newContact.*setter)(input);
			return true;
		}
	}
}

static void			printData(const Contact& contact)
{
	std::cout << "First Name:       " << contact.get_firstname() << std::endl;
	std::cout << "Last Name:        " << contact.get_lastname() << std::endl;
	std::cout << "Nickname:         " << contact.get_nickname() << std::endl;
	std::cout << "Phone Number:     " << contact.get_phonenumber() << std::endl;
	std::cout << "Darkest Secret:   " << contact.get_darkestsecret() << std::endl;
}

static std::string	alignRight(std::string str)
{
	std::string	newStr;

	if (str.length() == 10)
		return str;
	else if (str.length() > 10)
	{
		for (int i = 0; i < 9; i++)
			newStr += str[i];
		newStr += '.';
		return newStr;
	}
	else
	{
		for (size_t i = 0; i < 10 - str.length(); i++)
			newStr += ' ';
		newStr += str;
		return newStr;
	}
}

bool	PhoneBook::add()
{
	Contact		newContact;

	if (!setContact(newContact, "First Name:       ", &Contact::set_firstname))
		return false;
	if (!setContact(newContact, "Last Name:        ", &Contact::set_lastname))
		return false;
	if (!setContact(newContact, "Nickname:         ", &Contact::set_nickname))
		return false;
	if (!setContact(newContact, "Phone Number:     ", &Contact::set_phonenumber))
		return false;
	if (!setContact(newContact, "Darkest Secret:   ", &Contact::set_darkestsecret))
		return false;

	if (_count == _maxLength)
	{
		for (int i = 0; i < _maxLength - 1; i++)
			_contact[i].copy_data(_contact[i + 1]);
		_contact[_maxLength - 1].copy_data(newContact);
	}
	else
	{
		_contact[_count].copy_data(newContact);
		_count++;
	}
	return true;
}

bool	PhoneBook::search()
{
	std::string	input;
	int			index;

	if (_count == 0)
	{
		std::cout << "No contact saved yet." << std::endl;
		return true;
	}

	std::cout << "+-+----------+----------+----------+" << std::endl;
	for(size_t i = 0; i < (size_t)_count; i++)
	{
		std::cout << "|" << i << "|" << alignRight(_contact[i].get_firstname());
		std::cout << "|" << alignRight(_contact[i].get_lastname());
		std::cout << "|" << alignRight(_contact[i].get_nickname()) << "|" << std::endl;
	}
	std::cout << "+-+----------+----------+----------+" << std::endl;

	while (1)
	{
		std::cout << "Enter a number between 0 ~ " << _count - 1 << ": ";
		getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			return false;
		}
		if (input.length() != 1)
			continue;
		else
		{
			if (input[0] >= '0' && input[0] <= '8')
				index = input[0] - 48;
			else
				continue;
		}

		if (index >= _count)
			continue;

		std::cout << std::endl;
		printData(_contact[index]);
		break;
	}
	return true;
}
