#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"

int main(void)
{
    ClapTrap    tuna("Tuna");
    ScavTrap    mehmet("Mehmet");
    ClapTrap    ali("Ali");

    ali = mehmet;

    std::cout << "\n--- The battle begins ---\n" << std::endl;

    tuna.attack("Mehmet");

    mehmet.takeDamage(5);
    mehmet.beRepaired(3);

    std::cout << std::endl;

    mehmet.guardGate();

    std::cout << std::endl;

    mehmet.attack("Yagiz");
    mehmet.takeDamage(50);
    mehmet.attack("Yagiz");
    mehmet.takeDamage(60);
    mehmet.attack("Yagiz");

    return 0;
}