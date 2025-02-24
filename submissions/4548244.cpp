// dmopc21c8p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

#define ok "\n"

const int MN = 500005;
int n, m;
map<int, int> mp;
vector<int> out;

void del(int x) {
	mp[x] --;
	if (mp[x] == 0) {
		mp.erase(x);
	}
}

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		mp[x] ++;
	}
	out.push_back(mp.begin()->first);
	del(mp.begin()->first);
	for (int i = 1; i < n; i++) {
		auto x = mp.lower_bound(m - out.back());
		if (x == mp.end()) {
			cout << -1 << ok;
			return 0;
		}
		out.push_back(x->first);
		del(x->first);
		//for (auto k : mp) {
		//	cout << k.first << " " << k.second << "       ";
		//}
		//cout << ok;
	}
	for (int i = 0; i < n; i++) {
		cout << out[i] << (i == n - 1 ? ok : " ");
	}
	return 0;
}