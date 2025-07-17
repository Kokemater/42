#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int idx;
    int totalContacts;

public:
    void addContact(std::string newName, std::string newPhone)
    {
        contacts[idx].setContact(newName, newPhone);
    }
    void display(void)
    {
        for (int i = 0; i < idx; i++)
        {
            contacts[i].display();
        }
    }
};

#endif