#include "./Contact.hpp"

static std::string convertToPositive(std::string phonenumber)
{
	std::string	newNum;

	for (size_t i = 0; i < phonenumber.length(); i++)
	{
		if (phonenumber[i] == '-' || phonenumber[i] == '+' || std::isspace(phonenumber[i]))
			continue;
		newNum += phonenumber[i];
	}

	return newNum.empty() ? "0" : newNum;
}

Contact::Contact() : _firstname(""), _lastname(""), _nickname(""),
	_phonenumber(""), _darkestsecret("") { }

std::string Contact::get_firstname() const { return _firstname; }

std::string Contact::get_lastname() const { return _lastname; }

std::string Contact::get_nickname() const { return _nickname; }

std::string Contact::get_phonenumber() const { return _phonenumber; }

std::string	Contact::get_darkestsecret() const { return _darkestsecret; }

void		Contact::set_firstname(std::string firstname) { _firstname = firstname; }

void		Contact::set_lastname(std::string lastname) { _lastname = lastname; }

void		Contact::set_nickname(std::string nickname) { _nickname = nickname; }

void		Contact::set_phonenumber(std::string phonenumber) { _phonenumber = convertToPositive(phonenumber); }

void		Contact::set_darkestsecret(std::string darkestsecret) { _darkestsecret = darkestsecret; }

void		Contact::copy_data(Contact& other)
{
	_firstname = other._firstname;
	_lastname = other._lastname;
	_nickname = other._nickname;
	_phonenumber = other._phonenumber;
	_darkestsecret = other._darkestsecret;
}
