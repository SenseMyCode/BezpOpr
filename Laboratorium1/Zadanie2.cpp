#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file ("test.txt");

    char buffer[100];

    while (file.getline(buffer, 100)) {
        cout << buffer << endl;
    }

    file.close();
    return 0;
}