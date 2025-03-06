#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
#include <array>
#include <cstring>
#include <string>

using namespace std;

const int mn = 10005;
int n, m, x, y, in[mn];
vector<int> adj[mn];
bool v[mn];


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		adj[x].push_back(y);
		in[y] ++;
	}
	while (1) {
		int cur = -1;
		for (int i = 0; i < n; i++) {
			if (in[i] == 0) {
				in[i] --;
				cur = i;
				break;
			}
		}
		if (cur == -1) break;
		for (int k : adj[cur]) {
			in[k] --;
		}
	}
	sort(in, in + n + 1);
	if (in[n - 1] > 0) cout << "N\n";
	else cout << "Y\n";

}