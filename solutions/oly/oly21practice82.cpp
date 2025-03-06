#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a ,b;
    cin >> n >> a >> b;
    int lol = n / 2;
    if (n % 2 == 0) {
        cout << a * lol + b * lol << "\n";
    }
    else {
        cout << a * lol + b * lol + a << "\n";
    }
}