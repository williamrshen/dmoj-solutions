#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 105;
int n;
vector<int> arr;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            cout << arr[(n / 2) - i - 1] << " " << arr[(n / 2) + i] << " ";
        }
    }
    else {
        cout << arr[(n / 2)] << " "; 
        for (int i = 0; i < n / 2; i++) {
            cout << arr[(n / 2) + i + 1] << " " << arr[(n / 2) - i - 1] << " ";
        }
    }
}