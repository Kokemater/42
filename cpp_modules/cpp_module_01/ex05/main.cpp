#include "Harl.hpp"

int main(void)
{
    Harl myHarl;
    std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        myHarl.complain(complains[i]);
    }
    return (0);
}