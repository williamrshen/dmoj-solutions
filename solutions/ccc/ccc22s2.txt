#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define ok "\n"
#define ps pair<string, string>

const int MR = 1000005;
int x, y, G, ans = 0;
vector<ps> no, yes;
map<string, int> g;
set<string> gr[100005];

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> x;
    for (int i = 0; i < x; i++) {
        string a, b; cin >> a >> b;
        yes.push_back({ a, b });
    }
    cin >> y;
    for (int i = 0; i < y; i++) {
        string a, b; cin >> a >> b;
        no.push_back({ a, b });
    }
    cin >> G;
    for (int i = 0; i < G; i++) {
        string a, b, c; cin >> a >> b >> c;
        gr[i].insert(a); gr[i].insert(b); gr[i].insert(c);
        g[a] = i; g[b] = i; g[c] = i;
    }
    for (int i = 0; i < x; i++) {
        if (gr[g[yes[i].first]].count(yes[i].second) == 0) ans++;
    }
    for (int i = 0; i < y; i++) {
        if (gr[g[no[i].first]].count(no[i].second) != 0) ans++;
    }
    cout << ans << ok;
}