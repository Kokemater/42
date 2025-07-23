#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "ERROR: try with: ./harlFilter <level> " << std::endl;
        return (1);
    }
    std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    std::string level = argv[1];
    // check it exist
    bool correct = false;
    for (int i = 0; i < 4; i++)
    {
        if (level.compare(complains[i]) == 0)
        {
            correct = true;
            break;
        }
    }
    if (correct == false)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return (0);
    }
    Harl MyHarl;
    int a = level[0];
    switch (a)
    {
    case 'D':
        MyHarl.complain("DEBUG");
        break;
    case 'I':
        MyHarl.complain("INFO");
        break;
    case 'W':
        MyHarl.complain("WARNING");
        break;
    case 'E':
        MyHarl.complain("ERROR");
        break;
    default:
        break;
    }


    return (0);
}