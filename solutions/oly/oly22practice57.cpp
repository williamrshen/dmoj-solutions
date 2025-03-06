// olyquiz.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define ok "\n"
#define pi pair<int, int>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MN = 1e5 + 5;
int n, out = 0;
int fidx[MN], bidx[MN];
vector<int> a;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    scan(n);
    for (int i = 0; i < n; i++) {
        int x; scan(x);
        a.push_back(x);
    }
    if (n <= -1) {
        for (int i = 0; i < n; i++) {
            bool b = 0;
            int f = a[i];
            for (int j = i; j >= 0; j--) {
                if (a[j] == f) {
                    f -= 1;
                }
            }
            if (f != 0) {
                // cout << f << "aaa" << i << ok;
                continue;
            }
            f = a[i];
            for (int j = i + 1; j < n; j++) {
                if (a[j] == f) {
                    f -= 1;
                }
            }
            if (f != 0) {
                // cout << f << "bbb" << i << ok;
                continue;
            }
            out = max(a[i], out);
        }
        cout << out << ok;
    }
    else {
        memset(fidx, 1e6, sizeof(fidx));
        memset(bidx, -1, sizeof(bidx));
        int f = 0, b = 0;
        int l = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == l) {
                fidx[l] = i;
                l++;
                f++;
            }
        }
        l = 1;
        for (int i = n - 1; i >= 0;  i--) {
            if (a[i] == l) {
                bidx[l] = i;
                l++;
                b++;
            }
        }
        for (int i = 1; i < 1e5 + 5; i++) {
            if (fidx[i] < bidx[i]) {
                out = max(out, i);
            }
        }
        for (int i = 1; i < 5; i++) {
            // cout << fidx[i] << " " << bidx[i] << " " << ok;
        }
        cout << out << ok;
    }
}