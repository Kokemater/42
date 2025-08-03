#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    //FragTrap
    FragTrap ft("Carmen");
    ft.highFivesGuys();
    ft.printData();
    ft.setAttackDamage(10);
    ft.attack("Coco");
    ft.takeDamage(5);
    ft.beRepaired(3);
    ft.takeDamage(8);
    ft.takeDamage(90);
    ft.attack("Calamardo");
    ft.beRepaired(3);
    ft.printData();

    std::cout << "=============================" << std::endl;
    //tests for orthodoxal-cannonical-form
    FragTrap ft_default;
    ft_default.printData();
    FragTrap ft1 = ft;
    FragTrap ft2(ft);
    ft1.printData();
    ft2.printData();
    
    return 0;
}
