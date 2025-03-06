#include <iostream>
#include <array>

using namespace std;

#define ok "\n"

int n;

int main() {
    cin >> n;
    if (n == 1) {
        cout << "1" << ok;
    }
    else if (n == 2) {
        cout << "-1" << ok;
    }
    else if (n == 3) {
        cout << "1 3 2" << ok;
    }
    else if (n == 4) {
        cout << "1 3 2 4" << ok;
    }
    else if (n == 5) {
        cout << "1 3 2 4 5" << ok;
    }
    else if (n == 6) {
        cout << "1 3 2 4 5 6" << ok;
    }
    else if (n == 7) {
        cout << "1 3 2 4 5 6 7" << ok;
    }
    else {
        cout << "1 3 2 ";
        for (int i = 4; i < n; i++) {
            cout << i << " ";
        }
        cout << n << ok;
    }
}