// usaco22opens3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define ok "\n"

const int MN = 200005;
int q;
string s, t;
bool m[200][200];

bool c(char a, char b) {
    string x, y;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == a || s[i] == b) {
            x.push_back(s[i]);
        }
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == a || t[i] == b) {
            y.push_back(t[i]);
        }
    }
    return x == y;
}

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> s >> t;
    for (char a = 'a'; a <= 'r'; a++) {
        for (char b = a; b <= 'r'; b++) {
            m[a][b] = m[b][a] = c(a, b);
        }
    }
    cin >> q;
    while (q--) {
        string k; cin >> k;
        bool f = 1;
        for (int i = 0; i < k.size() && f; i++) {
            for (int j = i; j < k.size() && f; j++) {
                if (!m[k[i]][k[j]]) {
                    f = 0;
                }
            }
        }
        cout << (f ? "Y" : "N");
    }
}