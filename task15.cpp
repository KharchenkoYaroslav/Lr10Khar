#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream file("input.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char c1, c2;
    while (file.get(c1)) {
        if (file.get(c2)) {
            file.seekp(-2, ios::cur); 
            file << c2 << c1; 
        }
    }

    file.close();

    return 0;
}