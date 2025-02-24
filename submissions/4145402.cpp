#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>
#include <string>

using namespace std;

struct edge {
	int b, e, w;
	bool operator<(edge const& o) {
		return w < o.w;
	}
};

const int mn = 1e5 + 5;
int n, m, x, y;
int f[mn], par[mn];
vector<edge> e;

int find(int k) {
	if (par[k] == k) return k;
	else return par[k] = find(par[k]);
}

void merge(int k, int l) {
	k = find(k), l = find(l);
	par[k] = l;
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	for (int i = 0; i < mn; i++) par[i] = i;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> f[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		e.push_back({ x, y, 0 });
	}
	for (int i = 1; i < n; i++) {
		e.push_back({ i, i + 1, abs(f[i] - f[i + 1]) });
	}
	sort(e.begin(), e.end());
	sort(begin(e), end(e), [](const edge& a, const edge& b) { return a.w < b.w; });
	int out = 0, cnt = 0, idx = 0;
	while (cnt < n - 1) {
		edge nxt = e[idx++];
		int a = find(nxt.b), b = find(nxt.e);
		if (a != b) {
			out += nxt.w;
			merge(a, b);
			cnt++;
		}
	}
	cout << out << "\n";
}