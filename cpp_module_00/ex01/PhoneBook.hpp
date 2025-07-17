#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACTS 3

class PhoneBook
{
private:
    Contact contacts[MAX_CONTACTS];
    int idx;
    int totalContacts;
public:
    PhoneBook();
    void addContact(std::string firstName, std::string secondName, std::string nickName);
    void display(void);
};

#endif