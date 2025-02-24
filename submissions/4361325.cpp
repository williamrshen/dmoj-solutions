#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define forloop(i,a,b) for (int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a, x) for(auto& a : x)
typedef pair<int, int> pii;
typedef vector<int> vi;


void solve(){
	int n;
	cin>>n;

	int f[n+1], e[n+1];
	
	for (int i = 1; i<=n; ++i){
		cin>>f[i];
	}

	for (int i = 1; i<=n; ++i){
		cin>>e[i];
	}


	int dp[n+1] = {0};
	
	dp[1] = max(e[1], f[1]);
	if (n == 1){
		cout<<dp[1]<<"\n";
		return;
	}
	dp[2] = dp[1] + max(e[2], f[2]);

	for (int i = 3; i<=n; ++i){
		dp[i] = dp[i-1] + e[i];
		dp[i] = max(dp[i], max(f[i], e[i]) + e[i-1] + dp[i-2]);
		dp[i] = max(dp[i], max(f[i], e[i]) + max(f[i-1], e[i-1]) + e[i-2] + dp[i-3]);
		
	}
	
	cout<<dp[n]<<"\n";

}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);   
    solve();
	

}