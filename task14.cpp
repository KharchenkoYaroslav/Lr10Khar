#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("original.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string str, temp;

    while (getline(file, temp)) {
        str = temp + '\n' + str;
    }
    cout << "Reversed lines:\n" << str << endl;

    str.clear();
    file.clear();
    file.seekg(0, ios::beg);

    char c;
    while (file.get(c)) {
        str = c + str;
    }
    cout << "Reversed characters:\n" << str << endl;

    file.close();

    return 0;
}