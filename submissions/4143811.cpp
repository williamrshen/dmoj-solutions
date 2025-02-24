#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>
#include <string>

using namespace std;

const int mn = 2005;
int n, m, k, x, y;
vector<int> v1[mn], v2[mn];
bool v[mn];

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		v1[x].push_back(y);
		v2[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		memset(v, 0, mn);
		for (int a : v1[i]) {
			for (int b : v2[a]) {
				if (v[b]) {
					cout << "NO\n";
					return 0;
				}
				if (b != i) v[b] = 1;
			}
		}
	}
	cout << "YES\n";
	return 0;
}