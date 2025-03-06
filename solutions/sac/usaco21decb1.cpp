#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ok "\n"

const int MN = 5005;
int n;
long long out = 0;
vector<int> g, h;
string s;


int main() {
    cin >> n >> s;
    g.push_back(0); h.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'G') g.push_back(i);
        else h.push_back(i);
    }
    g.push_back(n + 1); h.push_back(n + 1);
    for (int i = 1; i < g.size() - 1; i++) {
        long long l = g[i] - g[i - 1], r = g[i + 1] - g[i];
        out += max(r - 2, 0LL);
        if (l > 1) out += max(r - 1, 0LL);
        if (l > 2) out += (l - 2) * r;
    }
    for (int i = 1; i < h.size() - 1; i++) {
        long long l = h[i] - h[i - 1], r = h[i + 1] - h[i];
        out += max(r - 2, 0LL);
        if (l > 1) out += max(r - 1, 0LL);
        if (l > 2) out += (l - 2) * r;
    }
    cout << out << ok;
}