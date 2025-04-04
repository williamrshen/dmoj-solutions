// vmss7wc16c3p2v2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b;
int vis[2005];
int dis[2005];
vector<int> adj[2005];

void dfs(int source, int dist) {
	if (vis[source]) {
		return;
	}
	else {
		vis[source] = true;
		dis[source] = dist + 1;
		for (auto x : adj[source]) {
			dfs(x, dist + 1);
		}
	}
}

int main()
{
	cin >> n >> m >> a >> b;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(a, 0);
	if (vis[b]) {
		cout << "GO SHAHIR!\n";
	}
	else {
		cout << "NO SHAHIR!\n";
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file