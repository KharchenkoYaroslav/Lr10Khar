#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("original.txt");

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int symbols[26];
    for (int i = 0; i < 26; i++)
    {
        symbols[i] = 0;
    }

    char c;
    while (file.get(c))
    {
        if (isalpha(c))
        {
            symbols[(int)tolower(c) - 97]++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << (char)(i + 97) << ": " << symbols[i] << endl;
    }

    file.close();

    return 0;
}