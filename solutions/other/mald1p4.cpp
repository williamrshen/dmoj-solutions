// mald1p4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 1e6 + 5;
int n, f, a[MN], h[MN];
long long out;

long long solve(int h[]) {
    stack<int> s;
    long long mx = 0;
    h[n + 1] = 0;
    for (int i = 1; i <= n + 1; i++) {
        while (s.size() and h[s.top()] >= h[i]) {
            int id = s.top();
            s.pop();
            if (h[id] > 1e9) {
                continue;
            }
            int ri = i, le = s.empty() ? 0 : s.top();
            mx = max(mx, 1LL * h[id] * (ri - le - 1));
        }
        s.push(i);
    }
    return mx;
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> f;
    memset(h, 0x3f, sizeof(h));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= f; i++) {
        int id, t; cin >> id >> t;
        h[id] = min(h[id], a[id] - t);
    }
    cout << solve(h) << ok;
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