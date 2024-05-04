#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream source("original.txt");
    ofstream dest("copy.txt");

    if (!source || !dest) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    char c;
    int count = 0;
    while (source.get(c)) {
        dest.put(c);
        count++;
    }

    cout << "Copied " << count << " characters." << endl;

    source.close();
    dest.close();

    return 0;
}