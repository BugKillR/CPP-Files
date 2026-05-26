#include "./Contact.hpp"

static bool isInRange(const std::string str, const size_t min, const size_t max)
{
	return min <= str.length() && str.length() <= max;
}

static bool isInRange(const std::string str, const size_t max)
{
	return str.length() <= max;
}

Contact::Contact(std::string name, std::string surname, std::string phonenum, std::string info)
{
	if (name.empty() || !isInRange(name, 0, 8))
	{
		std::cout << "Name must include minimum 1 letter and maximum 8 letter." << std::endl;
		return ;
	}
	if (surname.empty() || !isInRange(surname, 0, 10))
	{
		std::cout << "Surname must include minimum 1 letter and maximum 10 letter." << std::endl;
		return ;
	}
	if (phonenum.empty())
	{
		std::cout << "Empty phone number is not allowed!" << std::endl;
		return ;
	}
	if (!isInRange(info, 250))
		std::cout << "Info can't exceed 250 characters. Set as empty." << std::endl;
	else
		_info = info;
	
	_name = name;
	_surname = surname;
	_phonenum = phonenum;
}

std::string Contact::get_name()
{
	return _name;
}

std::string Contact::get_surname()
{
	return _surname;
}

std::string Contact::get_phonenum()
{
	return _phonenum;
}

std::string	Contact::get_info()
{
	return _info;
}

void		Contact::set_name(std::string name)
{

}

void		Contact::set_surname(std::string surname)
{

}

void		Contact::set_phonenum(std::string phonenum)
{

}

void		Contact::set_info(std::string info)
{
	
}