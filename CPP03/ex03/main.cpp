#include "./DiamondTrap.hpp"

int main(void)
{
    DiamondTrap d1("Mehmet");

    std::cout << "\n--- Identity check ---\n" << std::endl;

    d1.whoAmI();

    std::cout << "\n--- Combat test ---\n" << std::endl;

    d1.attack("Yagiz");
    d1.takeDamage(20);
    d1.beRepaired(10);

    std::cout << "\n--- Copy constructor test ---\n" << std::endl;

    DiamondTrap d2(d1);

    d2.whoAmI();
    d2.attack("Ege");

    std::cout << "\n--- Assignment operator test ---\n" << std::endl;

    DiamondTrap d3("Ali");

    d3.whoAmI();

    d3 = d1;

    d3.whoAmI();

    std::cout << "\n--- Death test ---\n" << std::endl;

    d1.takeDamage(200);
    d1.attack("Yagiz");
    d1.beRepaired(10);

    std::cout << "\n--- End of program ---\n" << std::endl;

    return 0;
}