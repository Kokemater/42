#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include "PhoneBook.hpp"

void get_data(std::string data_name, std::string &data)
{
    do
    {
        std::cout << data_name << ": ";
        std::getline(std::cin, data);
        if (data.empty())
            std::cout << "The " << data_name << " cannot be empty. Please enter a valid value." << std::endl;
    }
    while(data.empty());
}

std::string strip(const std::string& s) 
{
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

bool isNumber(const std::string& s) 
{
    if (s.empty()) 
        return false;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

int main() 
{
    PhoneBook phoneBook;
    std::string command, firstname, lastname, nickname, phonenumber, darkestsecret, input;
    int index;

    while (true) 
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        command = strip(command);

        if (std::cin.eof()) break;

        if (command == "ADD")
        {
            get_data("firstname", firstname);
            get_data("lastname", lastname);
            get_data("nickname", nickname);
            get_data("phonenumber", phonenumber);
            get_data("darkestsecret", darkestsecret);
            phoneBook.addContact(firstname, lastname, nickname, phonenumber, darkestsecret);
        }
        else if (command == "SEARCH")
        {
            
            phoneBook.display();
            std::cout << "INDEX: ";
            std::getline(std::cin, input);
            
            if (!isNumber(input) || strip(input).length() >= 3)
            {
                std::cout << "Invalid input. Index must be numeric.\n";
            }
            else
            {
                index = std::atoi(input.c_str());
                phoneBook.longDisplay(index);
            }
        }
        else if (command == "EXIT")
            break;
    }
    return 0;
}
