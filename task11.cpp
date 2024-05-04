#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

class account
{
    int custnum;
    char name[80];
    double balance;

public:
    account(int c, char *n, double b)
    {
        custnum = c;
        strcpy(name, n);
        balance = b;
    }
    friend ostream &operator<<(ostream &stream, account &obj);
};
ostream &operator<<(ostream &stream, account &obj)
{
    stream << "Number: " << obj.custnum << ", Name: " << obj.name << ", Balance: " << setprecision(5) << obj.balance << endl;
    return stream;
}

int main()
{
    ofstream file("output.txt");

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    account vasy = account(12345, (char*)"Vasy" , 0);

    file << vasy;

    file.close();

    return 0;
}