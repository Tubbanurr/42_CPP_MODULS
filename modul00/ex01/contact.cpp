#include "contact.hpp"

void Contact::setFirstName(const std::string& name)
{
    _firstName = name;
}

void Contact::setLastName(const std::string& name)
{
    _lastName = name;
}

void Contact::setNickname(const std::string& name)
{
    _nickname = name;
}

void Contact::setPhoneNumber(const std::string& number)
{
    _phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string& secret)
{
    _darkestSecret = secret;
}

std::string Contact::getFirstName() const
{
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

std::string Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return _darkestSecret;
}
