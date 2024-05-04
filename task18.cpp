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
    while (source.get(c)) {
        if (isupper(c)){
            c = tolower(c);
        }
        else if(islower(c)){
            c = toupper(c);
        }
        dest.put(c);
    }

    source.close();
    dest.close();

    return 0;
}