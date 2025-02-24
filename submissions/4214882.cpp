#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mpr make_pair
#define pb push_back
#define vt vector
typedef unsigned long long ull;	 typedef long long ll;	typedef long double ld;
template <typename C> void UNIQUE(vector<C>& v) { sort(all(v)); v.resize(unique(all(v)) - v.begin()); }
template <typename T> int sz(T& v) { return (int)(v.size()); }

template<class T> void fin(T& x) { cin >> x; }
void fin(double& d) {
	string t; fin(t);
	d = stod(t);
}
void fin(ld& d) {
	string t; fin(t);
	d = stold(t);
}
template<class H, class... T> void fin(H& h, T&...t) {
	fin(h); fin(t...);
}
template<class A> void fin(vector<A>& x) {
	for (auto& a : x) { fin(a); }
}

string to_string(char c) { return string(1, c); }
string to_string(bool b) { return b ? "true" : "false"; }
string to_string(const char* s) { return string(s); }
string to_string(string s) { return s; }
string to_string(vt<bool> v) {
	string res;
	for (int i = 0; i < (int)v.size(); i++)
		res += char('0' + v[i]);
	return res;
}
template<class T> string to_string(T v) {
	bool f = 1; string res;
	for (auto& x : v) {
		if (!f)
			res += ' ';
		f = 0;
		res += to_string(x);
	}
	return res;
}

template<class A> void write(A x) { cout << to_string(x); }
template<class H, class... T> void write(const H& h, const T&... t) { write(h); write(t...); }

void print() { write("\n"); }
template<class H, class... T> void print(const H& h, const T&... t) {
	write(h);
	if (sizeof...(t))
		write(' ');
	print(t...);
}

int n, t, k, d; vt<vt<pair<int, int>>> adj(5005); vt<pair<int, int>> city;

void dijkstra(int src) {
	int dis[5005]; memset(dis, 0x3f3f3f3f, sizeof dis);
	priority_queue<int, vt<int>, greater<int> > pq; pq.push(src); dis[src] = 0;

	while (sz(pq)) {
		int cur = pq.top(); pq.pop();

		for (pair<int, int>& p : adj[cur]) {
			if (dis[cur] != 0x3f3f3f3f && dis[cur] + p.se < dis[p.fi]) {
				dis[p.fi] = dis[cur] + p.se;
				pq.push(p.fi);
			}
		}
	}
	int out = 0x3f3f3f3f;
	for (auto c : city) {
		out = min(out, dis[c.first] + c.second);
	}
	cout << out << "\n";
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(0);
	fin(n, t);
	for (int i = 0; i < t; i++) {
		int x, y, w; fin(x, y, w);
		adj[x].pb(mpr(y, w)); adj[y].pb(mpr(x, w));
	}
	fin(k);
	for (int i = 0; i < k; i++) {
		int x, w; cin >> x >> w;
		city.pb({ x,w });
	}
	fin(d);
	dijkstra(d);
	return 0;
}