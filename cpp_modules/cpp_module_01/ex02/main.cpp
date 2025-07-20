#include <iostream>
#include <string>

int main(void)
{
    std::string text = "HI THIS IS BRAIN";
    std::string *stringPTR = &text;
    std::string &stringREF = text;

    std::cout << "stringPTR: " << stringPTR << std::endl
              << "stringREF: " << &stringREF <<std::endl;

    std:: cout << "-----------" << std::endl;
    
    std::cout << "stringPTR: " << *stringPTR << std::endl
              << "stringREF: " << stringREF <<std::endl;

}