#include <string>
#include <iostream>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string *brainPtr = &brain;
    std::string &brainRef = brain;

    std::cout << "Memory address of brain: " << &brain << std::endl;
    std::cout << "Memory address of string brainPtr: " << brainPtr << std::endl;
    std::cout << "Memory address of string brainRef: " << &brainRef << std::endl;

    std::cout << "Value of string: " << brain << std::endl;
    std::cout << "Value pointed to by brainPtr: " << *brainPtr << std::endl;
    std::cout << "Value pointed to by brainRef: " << brainRef << std::endl;

    return 0;
}