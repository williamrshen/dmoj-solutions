#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

#define scanu(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MN = 1e5;

vector<int> adj[MN+1];
int tme[MN+1];
int dist[MN+1];
int ind[MN+1];
int dsu[MN+1];
vector<int> zeros[MN+1];

int find(int x) {
	if (x == dsu[x]) {
		return x;
	} else {
		return dsu[x] = find(dsu[x]);
	}
}

int main()
{
	int n;
	scanu(n);
	for (int i = 1; i <= n; i++) {
		dsu[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int r;
		scanu(tme[i]);
		scanu(r);
		ind[i] = r;
		if (r == 0) {
			zeros[find(i)].push_back(i);
		} else {
			for (int j = 0; j < r; j++) {
				int x;
				scanu(x);
				adj[x].push_back(i);
				int a = find(x);
				int b = find(i);
				if (a != b) {
					dsu[a] = b;
					if (zeros[a].size() > zeros[b].size()) {
						 swap(zeros[a], zeros[b]);
					}
					for (int q : zeros[a]) {
						zeros[b].push_back(q);
					}
					vector<int>().swap(zeros[a]);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (find(i) == 0) {
			continue;
		}
		queue<int> q;
		for (int j : zeros[find(i)]) {
			dist[j] = tme[j];
			q.push(j);
		}
		dsu[find(i)] = 0;
		int mx = 0;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			mx = max(dist[cur], mx);
			for (int e : adj[cur]) {
				ind[e]--;
				dist[e] = max(dist[cur]+tme[e], dist[e]);
				if (ind[e] == 0) {
					q.push(e);
				}
			}
		}
		ans = max(mx, ans);
	}
	printf("%d\n", ans);
}