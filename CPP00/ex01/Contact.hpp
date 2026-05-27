#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdlib>
# include <cctype>

class Contact {
private:
    std::string _firstname;
    std::string _lastname;
    std::string _nickname;
    std::string _phonenumber;
    std::string _darkestsecret;
public:
    Contact();
    
    std::string	get_firstname() const;
    std::string	get_lastname() const;
    std::string get_nickname() const;
    std::string	get_phonenumber() const;
    std::string	get_darkestsecret() const;

    void		set_firstname(std::string firstname);
	void		set_lastname(std::string lastname);
    void        set_nickname(std::string nickname);
	void		set_phonenumber(std::string phonenumber);
	void		set_darkestsecret(std::string darkestsecret);

    void        copy_data(Contact& other);
};

#endif