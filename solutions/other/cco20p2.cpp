// cco20p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
#define ok "\n"

const int MN = 2e5 + 5;
int n, a[MN], bit[MN];
vector<int> d[MN];
priority_queue<int> q;

void upd(int pos, int val) {
    for (int i = pos; i <= n; i += i & -i) {
        bit[i] += val;
    }
}

int qry(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        d[x].push_back(i);
    }
    for (int i = n; i >= 1; i--) {
        for (int x : d[i]) {
            q.push(x);
        }
        if (q.empty()) {
            cout << -1 << ok;
            return 0;
        }
        a[i] = q.top();
        q.pop();
    }
    int out = 0;
    for (int i = 1; i <= n; i++) {
        upd(a[i], 1);
        out += i - qry(a[i]);
    }
    cout << out << ok;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file