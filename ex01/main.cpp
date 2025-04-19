#include "Zombie.hpp"

int main() {
    int N = 10;
    Zombie *horde = zombieHorde(N, "Paco");
    if (!horde) {
        std::cout << "Failed to create zombie horde." << std::endl;
        return 1;
    }
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}