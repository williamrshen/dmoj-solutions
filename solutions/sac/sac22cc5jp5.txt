// sac22cc5jp5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

using namespace std;

#define ok "\n"

const int MN = 2 * 1e5 + 5;
int n, dp[26];
string s;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n; 
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int v = 0, mx = 0, c = s[0] - 'a';
        for (int i = 1; i < s.size(); i++) {
            v += (s[i] == s[i - 1]);
        }
        for (int i = 0; i < 26; i++) {
            mx = max(mx, dp[i] + (i == c));
        }
        dp[s.back() - 'a'] = max(dp[s.back() - 'a'], v + mx);
    }
    int out = 0;
    for (int i = 0; i < 26; i++) {
        out = max(out, dp[i]);
    }
    cout << out << ok;
}