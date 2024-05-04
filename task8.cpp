#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream phones("phones.txt");

    if (!phones)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    char name[50];
    char surname[50];
    int j = 1;

    while (j != 0)
    {
        
        cout << "Write name, surname, number (number 0 to fin):";
        cin >> name >> surname >> j;
        if (j == 0){
            break;
        } 
        phones << name << " " << surname << " " << j << endl;
    }

    phones.close();

    return 0;
}