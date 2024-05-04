#include <iostream>
#include <iomanip> 
using namespace std;

istream& findalpha(istream& stream) {
    char c;
    while(stream.get(c)){
        if(isalpha(c)){
            stream.unget();
            return stream;
        }
    }
    return stream;
}

int main() {
    string str;
    cin >> findalpha >> str;

    cout << str << endl;

    return 0;
}