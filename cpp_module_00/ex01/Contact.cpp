#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
    index = "";
    firstName = "";
    lastName = "";
    nickName = "";
}

void Contact::setContact(std::string firstName, std::string lastName, std::string nickName)
{
    firstName = firstName;
    lastName = lastName;
    nickName = nickName;
}
void Contact::display()
{
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << (firstName) << "|"
              << std::setw(10) << (lastName) << "|"
              << std::setw(10) << (nickName) << "\n";
}