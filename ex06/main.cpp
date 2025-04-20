#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl harl;

    if (argc != 2) {
        std::cerr << RED << "Usage: " << argv[0] << " <level>" << RESET << std::endl;
        return 1;
    }

    harl.filter(argv[1]);

    return 0;
}