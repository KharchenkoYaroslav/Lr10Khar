#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define SIZE 40

class inventory {
    char item[SIZE]; 
    int onhand;      
    double cost;     
public:
    inventory(char *i, int o, double c) {
        strcpy(item, i);
        onhand = o;
        cost = c;
    }

    void store(fstream &stream) {
        stream << item << " " << onhand << " " << cost << endl;
    }


    void retrieve(fstream &stream, int n) {
        
        stream.seekg(ios::beg); 
        for (int i = 1; i < n; i++) {
            string temp;
            getline(stream, temp); 
        }
        stream >> item;  
        stream >> onhand;         
        stream >> cost;
    }

    friend ostream &operator<<(ostream &stream, const inventory &obj);
    friend istream &operator>>(istream &stream, inventory &obj);
};

ostream &operator<<(ostream &stream, const inventory &obj) {
    stream << obj.item << ": " << obj.onhand;
    stream << " on hand at $" << obj.cost << '\n';
    return stream;
}

istream &operator>>(istream &stream, inventory &obj) {
    cout << "Enter item name: ";
    stream >> obj.item;
    cout << "Enter number on hand: ";
    stream >> obj.onhand;
    cout << "Enter cost: ";
    stream >> obj.cost;
    return stream;
}

int main() {
    inventory ob1((char*)"obj1", 1, 5);
    inventory ob2((char*)"obj2", 2, 10);

    fstream file("inventory.txt", ios::in | ios::out); 
    if (!file) {
        cout << "Cannot open file.\n";
        return 1;
    }

    ob1.store(file);
    ob2.store(file);

    file.seekg(0, ios::beg);

    inventory ob3((char*)"", 0, 0.0);
    ob3.retrieve(file, 2); 

    cout << "Retrieved: " << ob3;

    file.close();

    return 0;
}