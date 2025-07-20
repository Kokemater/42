#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {
    index = 0;
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
}

void Contact::setContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string darkestSecret, int index)
{
    this->index = index;
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickName = nickName;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}
void Contact::short_display()
{
    std::string fn = firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName;
    std::string ln = lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName;
    std::string nn = nickName.length() > 10 ? nickName.substr(0, 9) + "." : nickName;
    std::cout << std::setw(10) << index << "|"
              << std::setw(10) << fn << "|"
              << std::setw(10) << ln << "|"
              << std::setw(10) << nn << "\n";
}

void Contact::complete_display()
{
    std::string fn = firstName.length() > 10 ? firstName.substr(0, 9) + "." : firstName;
    std::string ln = lastName.length() > 10 ? lastName.substr(0, 9) + "." : lastName;
    std::string nn = nickName.length() > 10 ? nickName.substr(0, 9) + "." : nickName;
    std::cout << "-------------------------------" << std::endl;
    std::cout   << "index: " << index << std::endl
                << "firstname: " << firstName << std::endl
                << "secondname: " << lastName << std::endl
                << "nickName: " << nickName << std::endl
                << "phoneNumber: " << phoneNumber << std::endl
                << "darkestSecret: "<< darkestSecret << std::endl;
    std::cout << "-------------------------------" << std::endl;
}
