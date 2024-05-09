#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream source("original.txt");
    ofstream dest("output.txt");

    if (!source || !dest) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    char c;
    int count = 0;
    source.unsetf(ios::skipws);
    while (!source.eof()) {
        source >> c;
        if(!source.eof()){
            dest << c;
        } 
        count++;
    }

    cout << "Copied " << count << " characters." << endl;

    source.close();
    dest.close();

    return 0;
}