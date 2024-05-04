#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("original.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string str, temp;

    while(getline(file, temp)){
        str += temp + '\n';
    }
    cout << str << endl;

    file.close();

    return 0;
}