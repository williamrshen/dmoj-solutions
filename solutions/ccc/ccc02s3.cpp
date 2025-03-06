// ccc02s3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define int long long
#define pi pair<int, int>

const int MN = 380;
int r, c, m, desr[4], desc[4], lft[4], rit[4], top[4], bot[4], dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
char g[MN][MN];
set<pi> p[4];
vector<char> o;

void init(int d) {
    int r = 0, c = 0, cur = d;
    lft[d] = top[d] = 1e9;
    rit[d] = bot[d] = -1e9;
    for (char ch : o) {
        if (ch == 'F') {
            r += dir[cur][0];
            c += dir[cur][1];
            p[d].insert({ r, c });
        }
        if (ch == 'R') {
            cur = (cur + 1) % 4;
        }
        if (ch == 'L') {
            cur = (cur - 1 + 4) % 4;
        }
        lft[d] = min(lft[d], c);
        top[d] = min(top[d], r);
        rit[d] = max(rit[d], c);
        bot[d] = max(bot[d], r);
    }
    desr[d] = r;
    desc[d] = c;
}

void f(int rr, int cc) {
    for (int d = 0; d < 4; d++) {
        if (cc + lft[d] < 1 || cc + rit[d] > c || rr + top[d] < 1 || rr + bot[d] > r) {
            continue;
        }
        bool work = true;
        for (auto x : p[d]) {
            int dr = x.first, dc = x.second;
            if (g[rr + dr][cc + dc] == 'X') {
                work = false;
                break;
            }
        }
        if (work) {
            g[rr + desr[d]][cc + desc[d]] = '*';
        }
    }
}

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> g[i][j];
        }
    }
    cin >> m;
    o.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> o[i];
    }
    for (int d = 0; d < 4; d++) {
        init(d);
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (g[i][j] != 'X') {
                f(i, j);
;            }
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << g[i][j];
        }
        cout << "\n";
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