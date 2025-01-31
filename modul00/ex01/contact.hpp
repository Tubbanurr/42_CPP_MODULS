#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>

class Contact {

	private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;


	public:
    void setFirstName(const std::string& name);
    void setLastName(const std::string& name);
    void setNickname(const std::string& name);
    void setPhoneNumber(const std::string& number);
    void setDarkestSecret(const std::string& secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

#endif
