#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    idx = 0;
    totalContacts = 0;
}

void PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickName)
{
    contacts[idx].setContact(firstName, lastName, nickName);
    idx++;
    totalContacts++;
    if (totalContacts >= MAX_CONTACTS)
        totalContacts = MAX_CONTACTS;
    if (idx >= MAX_CONTACTS)
        idx = 0;
}
void PhoneBook::display(void)
{
    for (int i = 0; i < totalContacts; i++)
    {
        contacts[i].display();
    }
}