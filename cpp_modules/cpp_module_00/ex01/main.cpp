#include <string>
#include <iostream>
#include <limits>
#include "PhoneBook.hpp"

void get_data(std::string data_name, std::string &data)
{
    do
    {
        std::cout << data_name << ": ";
        std::getline(std::cin, data);
        if (!data[0])
            std::cout << "The " << data_name << " cannot be empty. Please enter a valid value." << std::endl;
    }
    while(!data[0]);
}

std::string strip(const std::string& s) {
    size_t start;
    size_t end;

    start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
        ++start;

    end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
        --end;
    return s.substr(start, end - start);
}

int main() {
    PhoneBook phoneBook;
    std::string command, firstname, lastname, nickname, phonenumber, darkestsecret;
    int index;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (std::cin.eof()) break;

        if (strip(command) == "ADD")
        {
            get_data("firstname", firstname);
            get_data("lastname", lastname);
            get_data("nickname", nickname);
            get_data("phonenumber", phonenumber);
            get_data("darkestsecret", darkestsecret);
            phoneBook.addContact(firstname, lastname, nickname, phonenumber, darkestsecret);
        }
        else if (strip(command) == "SEARCH")
        {
            
            phoneBook.display();
            std::cout << "INDEX: ";
            std::cin >> index;
            std::cin.ignore();
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Index must be a numerical.\n";
            }
            else
                phoneBook.long_display(index);
        }
        else if (strip(command) == "EXIT")
            break;
    }

    std::cout << "Exiting. All contacts lost.\n";
    phoneBook.display();

    return 0;
}