/*Project-------CPP_Game_Engine
 *File----------Test.h
 *Author--------Justin Kachele
 *Date----------11/16/2022
 *License-------Mozilla Public License Version 2.0
 ******************************************/
#include <iostream>
#include <fstream>

using std::cout;
using std::cerr;
using std::string;
using std::endl;

int main() {
    std::ifstream vert{"test.txt"};

    if (!vert) {
        cerr << "Failed to open test.txt" << endl;
    }

    while (vert) {
        string line;
        std::getline(vert, line);
        if (line.empty()) continue;
        cout << line << endl;
    }
    vert.close();

    return 0;
}
