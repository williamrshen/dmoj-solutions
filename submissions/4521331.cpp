#include <iostream>

using namespace std;

int main() {
    int n = 0;
    for (int i = 0; i < 250000000; i++) {
        string str = "asdasd";
        str += "a";
        if (str.length()) {
            n++;
        }
    }
    if (n) {
        cout << "Hello, World!" << endl;
    }
    return 0;
}