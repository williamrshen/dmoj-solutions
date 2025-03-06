#include <iostream>
#include <string>
#include <cstring>
#include <array>
#include <vector>

using namespace std;

#define ok "\n"

const int MS = 5000;
int n, sz, len, ans;
string s;

int eee(string x, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return r - l - 1;
}

void solve(string x) {
    sz = x.size();
    int st = 0, en = 0;
    for (int i = 0; i < sz; i++) {
        int len = max(eee(x, i, i), eee(x, i, i + 1));
        if (len > en - st) {
            st = i - (len - 1) / 2;
            en = i + len / 2;
        }
    }
    cout << en - st + 1 << ok;
}



int main() {
        cin >> s;
        solve(s);
    
}