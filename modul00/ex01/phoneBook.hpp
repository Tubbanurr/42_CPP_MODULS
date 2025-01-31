#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "contact.hpp"

class PhoneBook
{
	private:
        Contact _contacts[8];
        int count;

	public:
        PhoneBook();

        void addContact();
        void searchContact();

        std::string truncateField(const std::string& field);
        void displayContactDetails(const Contact& contact);

};

std::string trimAndCheckWhitespace(const std::string& str, bool& isWhitespaceOnly);
void welcome_phone();

#endif
