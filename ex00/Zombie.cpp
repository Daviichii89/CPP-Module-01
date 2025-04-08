#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

void Zombie::announce() {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}