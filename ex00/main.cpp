#include "Zombie.hpp"

int main() {
    Zombie* zombie = new Zombie("Zombie");
    zombie->announce();
    delete zombie;

    return 0;
}