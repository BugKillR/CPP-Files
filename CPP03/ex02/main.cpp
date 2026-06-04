#include "./ClapTrap.hpp"
#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int main(void)
{
    ClapTrap    tuna("Tuna");
    ScavTrap    mehmet("Mehmet");
    FragTrap    ahmet("Ahmet");

    std::cout << "\n--- The battle begins ---\n" << std::endl;

    ahmet.attack("Crook");
    ahmet.highFivesGuys();

    std::cout << std::endl;

    ahmet.takeDamage(40);
    ahmet.beRepaired(20);

    std::cout << "\n--- Team attack ---\n" << std::endl;

    mehmet.attack("Boss");
    ahmet.attack("Boss");

    std::cout << "\n--- Final round ---\n" << std::endl;

    mehmet.takeDamage(200);
    mehmet.attack("Boss");

    ahmet.takeDamage(150);
    ahmet.highFivesGuys();
    ahmet.attack("Boss");

    return 0;
}