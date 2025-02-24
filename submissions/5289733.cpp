// ccc10s3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define int long long
#define pi pair<int, int>

const int MN = 1e3 + 5;
int n, p[MN], k, mx = 1e6;

bool chk(int len) {
    int hy = 1e9;
    len *= 2;
    for (int st = 0; st < n && p[st] - p[0] <= len; st++) {
        int cnt = 1, far = p[st];
        for (int nxt = st + 1; nxt < n && p[nxt] + len - mx < p[st]; nxt++) {
            if (p[nxt] > far) {
                cnt++;
                far = p[nxt] + len;
            }
        }
        hy = min(hy, cnt);
    }
    return hy <= k;
}

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cin >> k;
    sort(p, p + n);
    int l = 0, r = mx, out = mx;
    while (l <= r) {
        int m = (l + r) / 2;
        if (chk(m)) {
            out = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    cout << out;
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