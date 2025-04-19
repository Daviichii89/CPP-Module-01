#include "Harl.hpp"

int main() {
    Harl harl;

    std::cout << "Choose a level to complain about:" << std::endl;
    std::cout << "DEBUG, INFO, WARNING, ERROR" << std::endl;

    std::cout << "Enter level: ";
    std::string level;

    std::cin >> level;

    harl.complain(level);

    return 0;
}