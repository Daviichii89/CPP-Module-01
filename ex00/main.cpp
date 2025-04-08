#include "Zombie.hpp"

int main() {
    Zombie* zombie = newZombie("Heapster");
    zombie->announce();
    delete zombie;
    randomChump("Stackster");
    return 0;
}