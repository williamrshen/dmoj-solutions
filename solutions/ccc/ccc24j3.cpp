#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int counts[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        counts[x]++;
    }

    int medal = 1;

    for (int i = 75; i >= 0; i--) {
        if (counts[i] != 0) {
            medal++;
            if (medal == 4) {
                cout << i << " " << counts[i] << "\n";
                return 0;
            }
        }
    }


}