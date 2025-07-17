#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
class Contact
{
private:
    std::string index;
    std::string firstName;
    std::string lastName;
    std::string nickName;

public:
    Contact();
    void setContact(std::string firstName, std::string lastName, std::string nickName);
    void display(void);
};

#endif