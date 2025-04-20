#include <string>
#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

std::string replaceAll(const std::string& line, const std::string& from, const std::string& to) {
    std::string newLine;
    size_t start_pos = 0;
    size_t found_pos;
    while ((found_pos = line.find(from, start_pos)) != std::string::npos) {
        newLine += line.substr(start_pos, found_pos - start_pos);
        newLine += to;
        start_pos = found_pos + from.length();
    }
    newLine += line.substr(start_pos);
    return newLine;
}

int ft_replace (std::string filename, std::string s1, std::string s2) {
    std::cout << BLUE << "Replacing " << s1 << " with " << s2 << " in file " << filename << "...\n" << RESET << std::endl;
    sleep(1);
    std::ifstream infile((filename).c_str());
    if (!infile) {
        std::cerr << RED << "Error: Could not open file " << filename << RESET << std::endl;
        return 1;
    }

    std::string outFilename = filename + ".replace";
    std::ofstream outfile((outFilename).c_str());
    if (!outfile) {
        std::cerr << RED << "Error: Could not create file " << outFilename << RESET << std::endl;
        infile.close();
        return 1;
    }

    std::string line;
    int replaceCount = 0;
    while (std::getline(infile, line)) {
        std::string modifiedLine = replaceAll(line, s1, s2);
        if (modifiedLine != line) replaceCount++;
        outfile << modifiedLine << std::endl;
    }
    if (replaceCount == 0) {
        infile.close();
        outfile.close();
        std::cerr << YELLOW << "No replacements made in file " << filename << RESET << std::endl;
        return 0;
    }
    std::cout << GREEN << "File " << filename << " has been replaced and saved as " << outFilename << RESET << std::endl;
    infile.close();
    outfile.close();
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << RED << "Use: " << argv[0] << " <filename> <s1> <s2>" << RESET << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    struct stat fileStat;
    if (stat(filename.c_str(), &fileStat) != 0 || !S_ISREG(fileStat.st_mode)) {
        std::cerr << RED << "Error: " << filename << " is not a regular file" << RESET << std::endl;
        return 1;
    }
    if (s1.empty() || s2.empty()) {
        std::cerr << RED << "Error: Empty arguments" << RESET << std::endl;
        return 1;
    }
    if (s1 == s2) {
        std::cerr << RED << "Error: No changes made, s1 and s2 are the same" << RESET << std::endl;
        return 1;
    }
    if (ft_replace(filename, s1, s2) != 0) {
        std::cerr << RED << "Error: Could not replace in file" << RESET << std::endl;
        return 1;
    }
    std::cout << GREEN << "Replacement completed successfully." << RESET << std::endl;
    return 0;
}