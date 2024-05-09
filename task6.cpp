#include <iostream>
#include <string>
using namespace std;

struct skipchars
{
    string &str;
};

istream& operator>>(istream& stream, skipchars output)
{
    string temp;
    if (stream >> temp) {
        for (int i = 0; i < (int)temp.size(); i += 10) {
            output.str += temp.substr(i, 5);
        }
    }
    return stream;
}

int main()
{
    string str;
    cout << "enter smth:\n";
    cin >> skipchars{str};
    cout << "entered string: " << str;
    return 0;
}