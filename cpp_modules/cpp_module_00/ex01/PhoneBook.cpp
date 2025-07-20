#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    idx = 0;
    totalContacts = 0;
}

void PhoneBook::addContact(std::string firstName, std::string secondName, std::string nickName, std::string phoneNumber, std::string darkestSecret)
{
    contacts[idx].setContact(firstName, secondName, nickName,phoneNumber, darkestSecret, idx);
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
        contacts[i].short_display();
    }
}

void PhoneBook::long_display(int index)
{
    if (index >= totalContacts || index < 0)
    {
        std:: cout << "Invalid input. Contact ID must exist" << std::endl;
        return ;
    }
    contacts[index].complete_display();
}