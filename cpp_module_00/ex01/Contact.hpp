#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
class Contact
{
private:
    std::string name;
    std::string number;

public:
    Contact();
    void setContact(std::string newName, std::string newPhone);
    void display(void);
};

#endif