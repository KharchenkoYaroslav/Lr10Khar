#include <iostream>
#include <iomanip>


using namespace std;

ostream &sethex(ostream &stream){
    stream << hex << uppercase << showbase;
    return stream;
}

ostream &reset(ostream &stream){
    stream << dec << nouppercase << noshowbase;
    return stream;
}

int main() {

    cout << sethex << 15 << endl;

    cout << reset << 15 << endl;

    return 0;
}