#include "Contact.hpp"
#include <iostream>

Contact::Contact() {
    name = "";
    number = "";
}

void Contact::setContact(std::string newName, std::string newPhone)
{
    name = newName;
    number = newPhone;
}
void Contact::display()
{
    std::cout << "name: " << name << std::endl << "number: " << number << std::endl;
}