#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

const int MN = 1005;
int m, n, vis[(int) 1e6 + 5];
vector<int> adj[(int)1e6 + 5];
int grid[MN][MN];

int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			adj[i * j].push_back(x);
			grid[i][j] = x;
		}
	}
	queue<int> q;
	q.push(1); vis[1] = 1;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		for (int x : adj[cur]) {
			if (!vis[x]) {
				vis[x] = 1;
				q.push(x);
			}
		}
		if (vis[m * n]) {
			cout << "yes" << ok;
			return 0;
		}
	}
	cout << "no" << ok;
}