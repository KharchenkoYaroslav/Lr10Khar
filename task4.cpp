#include <iostream>
#include <ctime>

using namespace std;

ostream &tdm(ostream &stream){
    time_t now = time(0);
    tm* time = localtime(&now);
    stream << "Time: " << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << endl;
    return stream;
}

int main() {

    cout << tdm;

    return 0;
}