#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


int n, m, first, second, l, sizers[1000001], par[1000001];

int parent(int z){
	return z == par[z] ? par[z] : par[z] = parent(par[z]);
}

void solve(){
	cin >> n >> m;

	for (int i = 1; i<=n; ++i){
		sizers[i] = 1;
		par[i] = i;
	}
	
	for (int i = 0; i<m; ++i){
		cin >> l;
		cin >> first;
	
		first = parent(first);

		for (int j = 0; j< l - 1; ++j){
			cin >> second;
				
			second = parent(second);

			if (first == second) continue;

			if (first > second)
				swap(first, second);


			sizers[first] += sizers[second];
			par[second] = first;
			
			}
	}


	
	cout << sizers[1] << '\n';
	for (int i = 1; i <= n; ++i){
		int x = parent(i);
	}

	for (int i = 1; i <= n; ++i){
		if (par[i] == 1)
			cout << i << ' ';
	}
	
	cout << '\n';
}






int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int testcases = 1;
	//cin >> testcases;
	for (int number_of_total_test_cases = 1; number_of_total_test_cases <= testcases; ++number_of_total_test_cases){ 
	

	//Google
	//cout<<"Case #"<<number_of_total_test_cases<<": ";
	// Normal
	solve();
	}
}