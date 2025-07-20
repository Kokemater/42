#include "Zombie.hpp"

int main(void)
{
    // HEAP
    std::cout << "--------------" << std::endl;
    Zombie *heap_zombie = newZombie("heapzombie");
    heap_zombie->announce();
    delete heap_zombie;
    std::cout << "--------------" << std::endl;

    std::cout << "--------------" << std::endl;
    // STACK
    randomChump("stackzombie");
    std::cout << "--------------" << std::endl;

}