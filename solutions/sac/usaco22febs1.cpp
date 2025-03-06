#include <iostream>
#include <set>
#include <vector>

using namespace std;

#define ok "\n"
#define int long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define MN 505

char _;
int n, arr[MN][MN];
bool vis[MN][MN];

int32_t main() {
	cin.tie(0); cin.sync_with_stdio(0);
	scan(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x; scan(x);
			arr[i][j] = x;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			vis[i][arr[i][j]] = 1;
			if (arr[i][j] == i) break;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (vis[i][k] && vis[k][j]) {
					vis[i][j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (vis[i][arr[i][j]] && vis[arr[i][j]][i]) {
				cout << arr[i][j] << ok;
				break;
			}
		}
	}
}