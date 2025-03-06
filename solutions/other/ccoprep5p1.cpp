// ccoprep5p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 1005;
int t, r, c, h[MN];
char cc;

int solve(int h[]) {
    stack<int> s; 
    int mx = 0;
    for (int i = 1; i <= c + 1; i++) {
        while (s.size() and h[s.top()] >= h[i]) {
            int id = s.top();
            s.pop();
            int ri = i, le = s.empty() ? 0 : s.top();
            mx = max(mx, h[id] * (ri - le - 1));
        }
        s.push(i);
    }
    return mx;
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> t;
    while (t--) {
        memset(h, 0, sizeof(h));
        int out = 0;
        cin >> r >> c;
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cin >> cc;
                if (cc == 'R') {
                    h[j] = 0;
                }
                else {
                    h[j] ++;
                }
            }
            out = max(out, solve(h));
        }
        cout << out * 3 << ok;
    }
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