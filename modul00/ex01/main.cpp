#include "phoneBook.hpp"

std::string trimAndCheckWhitespace(const std::string& str, bool& isWhitespaceOnly)
{
    std::string::size_type start = str.find_first_not_of(" \t\n\r\f\v\"\'");
	    if (start == std::string::npos)
        {
            isWhitespaceOnly = true;
            return "";
        }
    std::string::size_type end = str.find_last_not_of(" \t");
    std::string trimmed = str.substr(start, end - start + 1);
    isWhitespaceOnly = false;
    return trimmed;
}

void welcome_phone()
{
    std::cout << std::endl;
    std::cout << "              Welcome to the 80s Phonebook ☎                 " << std::endl;
    std::cout << "                                                              " << std::endl;
    std::cout << "                       Commands                               " << std::endl;
    std::cout << "                                                              " << std::endl;
    std::cout << "          1- Enter ADD    : To add a new contact.             " << std::endl;
    std::cout << "          2- Enter SEARCH : To search for a contact           " << std::endl;
    std::cout << "          3- Enter EXIT   : to quite the program.             " << std::endl;
    std::cout << "                                                              " << std::endl;
    std::cout << "                                                              " << std::endl;
}

int main() {
    PhoneBook phoneBook;
    std::string command;

	welcome_phone();

    while (true)
    {
        std::cout << "Enter command:" << std::endl;
        std::getline(std::cin, command);

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Command not found" << std::endl;
    }
    return 0;
}
