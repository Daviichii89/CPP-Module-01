#include <string>
#include <fstream>
#include <iostream>

void ft_replace (std::string filename, std::string s1, std::string s2) {
    std::ifstream infile((filename).c_str());
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    std::string outFilename = filename + ".replace";
    std::ofstream outfile((outFilename).c_str());

    std::string line;
    while (std::getline(infile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.replace(pos, s1.length(), s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Use: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (filename.empty() || s1.empty() || s2.empty()) {
        std::cerr << "Error: Empty arguments" << std::endl;
        return 1;
    }
    ft_replace(filename, s1, s2);
    return 0;
}