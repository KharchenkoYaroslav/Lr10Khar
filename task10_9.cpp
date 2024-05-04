#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    ifstream file("original.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int wordCount = 0;
    char ch;
    bool check = false;

    while (file.get(ch)) {
        if (isalnum(ch)) {
            if (!check) {
                check = true;
                wordCount++;
            }
        } else {
            check = false;
        }
    }

    cout << "Word count: " << wordCount << endl;

    file.close();

    return 0;
}