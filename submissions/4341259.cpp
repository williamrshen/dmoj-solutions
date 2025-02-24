#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;
 

const int MN = 1001;
int grid[MN][MN];
vector <int> adj[(int) 1e6 + 5];
 void solve(){
	 int m, n, num, first, last;
	 cin>>m>>n;

	 for (int i = 1; i<m+1; ++i){
		for (int j = 1; j<n+1; ++j){
			cin>>num;

			grid[i][j] = num;

			adj[i*j].push_back(num);
			}
		}
	 
	//bfs
	
	queue <int> q;
	bool vis[(int) 1e6 + 5];
	fill(vis, vis + (int) 1e6 + 5, 0);
	q.push(1); vis[1] = 1;

	while (q.size()){
		int cur = q.front(); q.pop();

		for (int x : adj[cur]){
			if (vis[x] == true) continue;
			q.push(x);
			vis[x] = 1;
		}
	}

	if (vis[m*n] == 1){
		cout<<"yes";
	}else{
		cout<<"no";
	}


}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}