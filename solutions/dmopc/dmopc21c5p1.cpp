#include <iostream>
#include <array>

using namespace std;

#define ok "\n"

const int MN = 1e6 + 5;
int n, arr[MN];

int main() {
    cin >> n;
    if (n == 1) {
        cout << "1" << ok;
    }
    else if (n == 3) {
        cout << "-1" << ok;
    }
    else if (n == 2) {
        cout << "-1" << ok;
    }
    else if (n == 4) {
        cout << "-1" << ok;
    }
    else if (n == 5) {
        cout << "2 4 5 3 1" << ok;
    }
    else if (n == 6) {
        cout << "6 2 4 5 3 1" << ok;
    }
    else if (n == 7) {
        cout << "6 2 4 5 3 1 7" << ok;
    }
    else {
        if (n % 2 == 0) {
            for (int i = n; i >= 6; i-= 2) {
                cout << i << " ";
            }
            cout << "2 4 5 3 1 ";
            for (int i = 7; i < n - 2; i += 2) {
                cout << i << " ";
            }
            cout << n - 1 << ok;
        }
        else {
            for (int i = n - 1; i >= 6; i -= 2) {
                cout << i << " ";
            }
            cout << "2 4 5 3 1 ";
            for (int i = 7; i <= n - 2; i += 2) {
                cout << i << " ";
            }
            cout << n << ok;
        }
    }
}