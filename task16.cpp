#include <iostream>
#include <iomanip> 
using namespace std;

ostream& tab20(ostream& stream) {
    return stream << '\t' << '\t' << '\t' << setw(20);
}

int main() {
    cout << "Hello" << endl;

    cout << tab20 << "Hello" << endl;

    return 0;
}