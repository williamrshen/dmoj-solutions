#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;


#define ok "\n"
#define pb push_back

const int MN = 100005;
int n, m, i, j, t[4 * MN], arr[MN];
char o;

void build(int l, int r, int idx) {
	if (l == r) t[idx] = arr[l];
	else {
		int mid = (l + r) / 2;
		build(l, mid, idx * 2);
		build(mid + 1, r, idx * 2 + 1);
		t[idx] = min(t[idx * 2], t[idx * 2 + 1]);
	}
}

void upd(int l, int r, int cidx, int cval, int idx) {
	if (l == r) t[idx] = cval;
	else {
		int mid = (l + r) / 2;
		if (cidx <= mid) upd(l, mid, cidx, cval, idx * 2);
		else upd(mid + 1, r, cidx, cval, idx * 2 + 1);
		t[idx] = min(t[idx * 2], t[idx * 2 + 1]);
	}
}

int qry(int l, int r, int ql, int qr, int idx) {
	if (r < ql || l > qr) return 0x3f3f3f3f;
	else if (ql <= l && qr >= r) return t[idx];
	else {
		int mid = (l + r) / 2;
		int left = qry(l, mid, ql, min(qr, mid), idx * 2);
		int right = qry(mid + 1, r, max(ql, mid + 1), qr, idx * 2 + 1);
		return min(left, right);
	}
}


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	build(1, n, 1);
	while (m--) {
		cin >> o >> i >> j;
		if (o == 'Q') {
			i++; j++;
			cout << qry(1, n, i, j, 1) << ok;
		}
		else {
			i++;
			upd(1, n, i, j, 1);
		}
	}
}