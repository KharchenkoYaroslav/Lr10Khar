#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;

class Stack
{
public:
    void push(fstream &stream, string str);
    string pop(fstream &stream);
};

void Stack::push(fstream &stream, string str)
{
    stream << str << ' ';
}

string Stack::pop(fstream &stream) {
    string str = "";
    char ch;
    
    stream.seekg(-2, ios::cur);
    
    for (int i = stream.tellg(); i >= 0; i--) {
        stream.seekg(i, ios::beg);
        ch = stream.peek();
        if (ch == ' ') {
            stream.seekg(i+1, ios::beg);
            break;
        }
    }
    
    int temp = stream.tellg();

    stream >> str;

    stream.seekg(temp, ios::beg);
    
    return str;
}

int main()
{
    SetConsoleOutputCP(65001);

    Stack s1;
    int i;

    fstream file("stack.txt", ios::in | ios::out);
    if (!file)
    {
        cout << "Cannot open file.\n";
        return 1;
    }

    s1.push(file, "word1");
    s1.push(file, "word2");
    s1.push(file, "word3");

    for (i = 0; i < 3; i++)
    {
        cout << "Витягнути з s1: " << s1.pop(file) << endl;
    }

    return 0;
}