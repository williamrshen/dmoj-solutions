#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int t, c, ans;
vector<int> chores;

int main() {
    cin >> t >> c;
    for (int i = 0; i < c; i++) {
        int x; cin >> x;
        chores.push_back(x);
    }

    sort(chores.begin(), chores.end());
    







    int total = 0;
    for (int i = 0; i < c; i++) {
        if (total <= t) {
            total += chores[i];
            ans++;
        }

    }
    cout << ans - 1 << "\n";

}