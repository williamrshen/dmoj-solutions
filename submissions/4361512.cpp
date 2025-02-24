#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

typedef long long ll;


#define ok "\n"
#define pb push_back

const int MN = 100005;
int n, to[MN];

int dfs(int cur, int st) {
	if (to[cur] == st) return 1;
	else return dfs(to[cur], st) + 1;
}


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n;
	while (n != 0) {
		for (int i = 1; i <= n; i++){
			int a, b; cin >> a >> b;
			to[a] = b;
		}
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			ans = lcm(ans, dfs(i, i));
		}
		cout << ans << ok;
		cin >> n;
	}
}