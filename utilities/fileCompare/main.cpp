// File Compare v1.0
// Made by mrdoge <3
#include <iostream>
#include <fstream>
#include "colormod.h"

int main(int argc, char** argv) {
    // Color modifiers
    Color::Modifier red(Color::FG_RED);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier def(Color::FG_DEFAULT);

    // Checking if there are enough arguments
    if(argc != 3) {
        std::cout << red << "You need to pass two files as arguments!" << def;

        return 0;
    }

    // String for getline output storage
    std::string text1;
    std::string text2;

    // Opening files and creating an output one
    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);
    std::ofstream out("out.txt");

    // Variable for storing detected differences between files
    int differences = 0;

    // Checking if files have the same contents
    while (std::getline (file1, text1)) {
        std::getline(file2, text2);
        if(text1 != text2) {
            out << text1 << " | " << text2 << "\n";
            differences++;
        }
    }

    // Checking if loop reported any differences between files
    if(differences == 0) {
        std::cout << green << "Files are the same" << def;
    } else {
        std::cout << red << "Files are different. Check out.txt for detailed differences" << def;
    }

    // Closing files
    file1.close();
    file2.close();
    out.close();

    return 0;
}