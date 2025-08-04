#include "ScavTrap.hpp"

int main()
{
    //ClapTrap
    ClapTrap ct("Alba");
    ct.printData();
    ct.setAttackDamage(10);
    ct.attack("Alonso");
    ct.takeDamage(5);
    ct.beRepaired(3);
    ct.takeDamage(8);
    ct.attack("Alicia");
    ct.beRepaired(3);
    ct.printData();

    std::cout << "==========================" << std::endl;
    //SlapTrap
    ScavTrap st("Bernardo");
    st.guardGate();
    st.printData();
    st.setAttackDamage(10);
    st.attack("Bob");
    st.takeDamage(5);
    st.beRepaired(3);
    st.takeDamage(8);
    st.takeDamage(90);
    st.attack("Biballooo");
    st.beRepaired(3);
    st.printData();

    std::cout << "=============================" << std::endl;
    
    return 0;
}
