#include "bits/stdc++.h"
using namespace std;

#define vt vector
#define mpr make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) (int)(x.size())

typedef long long ll;	typedef long double ld;

const int MN = 50003;
int n, q, LOG[MN];
ll st[25][MN], stt[25][MN];

void lll() {
    LOG[1] = 0;
    for (int i = 2; i < MN; i++) {
        LOG[i] = LOG[i / 2] + 1;
    }
}

int main() {
    cin.tie(nullptr) -> sync_with_stdio(0);
    lll();
	cin >> n >> q;
	vt<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++) { stt[0][i] = arr[i]; st[0][i] = arr[i]; }
	for (int i = 1; i < 26; i++) {
		for (int j = 0; j + (1 << i) <= n; j++) {
			stt[i][j] = max(stt[i-1][j], stt[i-1][j+(1<<(i-1))]);
			st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
		}
	}

	for (int qq = 0; qq < q; qq++) {
		int L, R; cin >> L >> R;
		L--; R--;
		int j = LOG[R-L+1];
		int res = min(st[j][L], st[j][R-(1<<j)+1]);
		int _es = max(stt[j][L], stt[j][R-(1<<j)+1]);
		cout << _es-res << endl;
	}
}