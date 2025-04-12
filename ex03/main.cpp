#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    Weapon club("crude spiked club");

    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    Weapon axe("rusty axe");
    HumanB jim("Jim");
    jim.attack();
    jim.setWeapon(axe);
    jim.attack();
    axe.setType("shiny battle axe");
    jim.attack();

    return 0;
}
