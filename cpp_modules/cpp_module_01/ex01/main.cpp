#include "Zombie.hpp"

int main(void)
{
    int n = 10;
    std::string name = "nombre";
    Zombie *horde = zombieHorde(n, name);


    for (int i = 0; i < n; i++)
    {
        horde[i].announce();
    }
    return (0);
}