#include <string>
#include <iostream>

#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command, firstname, lastname, nickname;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof()) break;

        if (command == "ADD")
        {
            std::cout << "firstname: ";
            std::getline(std::cin, firstname);
            std::cout << "lastname: ";
            std::getline(std::cin, lastname);
            std::cout << "nickname: ";
            std::getline(std::cin, nickname);
            phoneBook.addContact(firstname, lastname, nickname);
        }
        else if (command == "SEARCH")
            break;
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Try again.\n";
    }

    std::cout << "Exiting. All contacts lost.\n";
    phoneBook.display();

    return 0;
}