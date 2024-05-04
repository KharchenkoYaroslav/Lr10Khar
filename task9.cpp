#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("original.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int wordCount = 0;
    string word;
    while (file >> word) {
        wordCount++;
    }

    cout << "Word count: " << wordCount << endl;

    file.close();

    return 0;
}