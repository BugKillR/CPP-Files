#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
private:
    std::string _name;
    std::string _surname;
    std::string _phonenum;
    std::string _info;
public:
    Contact(std::string name, std::string surname, std::string phonenum, std::string info);
    std::string	get_name();
    std::string	get_surname();
    std::string	get_phonenum();
    std::string	get_info();
    void		set_name(std::string name);
	void		set_surname(std::string surname);
	void		set_phonenum(std::string phonenum);
	void		set_info(std::string info);
};

#endif