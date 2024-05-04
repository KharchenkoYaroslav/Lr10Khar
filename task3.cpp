#include <iostream>
#include <iomanip>
using namespace std;

class date
{
    char d[9]; // store date as string : mm/dd/yy
public:
    friend ostream &operator<<(ostream &stream, date &obj);
    friend istream &operator>>(istream &stream, date &obj);
};

ostream &operator<<(ostream &stream, date &obj)
{
    stream << "Date: " << obj.d << endl;
    return stream;
}
istream &operator>>(istream &stream, date &obj)
{
    cout << "Enter date in (mm/dd/yy): ";
    stream >> obj.d; // по хорошому додати перевірку через банальний цикл, але тут і так 21 завдання

    return stream;
}

int main()
{
    date a;
    cin >> a;
    cout << a;

    return 0;
}