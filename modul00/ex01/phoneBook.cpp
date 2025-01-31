#include "phoneBook.hpp"

PhoneBook::PhoneBook() : count(0) {}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;
    bool isWhitespaceOnly;

    do {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        input = trimAndCheckWhitespace(input, isWhitespaceOnly);
    } while (input.empty() || isWhitespaceOnly);
    newContact.setFirstName(input);

    do {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        input = trimAndCheckWhitespace(input, isWhitespaceOnly);
    } while (input.empty() || isWhitespaceOnly);
    newContact.setLastName(input);

    do {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
        input = trimAndCheckWhitespace(input, isWhitespaceOnly);
    } while (input.empty() || isWhitespaceOnly);
    newContact.setNickname(input);

    do {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
        input = trimAndCheckWhitespace(input, isWhitespaceOnly);
    } while (input.empty() || isWhitespaceOnly);
    newContact.setPhoneNumber(input);

    do {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        input = trimAndCheckWhitespace(input, isWhitespaceOnly);
    } while (input.empty() || isWhitespaceOnly);
    newContact.setDarkestSecret(input);

    _contacts[count % 8] = newContact;
    count++;
}
void PhoneBook::searchContact()
{
    if (count == 0)
    {
        std::cout << "Phone book is empty!" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count && i < 8; i++)
    {
        std::cout << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncateField(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << truncateField(_contacts[i].getLastName()) << "|"
                  << std::setw(10) << truncateField(_contacts[i].getNickname()) << std::endl;
    }

    std::cout << "Enter index to view details: ";
    std::string indexStr;

    std::getline(std::cin, indexStr);
    int index = atoi(indexStr.c_str());

    if (index > 0 && index <= 8 && index <= count)
        displayContactDetails(_contacts[index - 1]);
    else
        std::cout << "Invalid index!" << std::endl;
}

std::string PhoneBook::truncateField(const std::string& field)
{
    if (field.length() > 10) {
        return field.substr(0, 9) + ".";
    } else {
        return field;
    }
}

void PhoneBook::displayContactDetails(const Contact& contact)
{
    std::cout << "First Name: " << contact.getFirstName() << std::endl;
    std::cout << "Last Name: " << contact.getLastName() << std::endl;
    std::cout << "Nickname: " << contact.getNickname() << std::endl;
    std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}

