#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

#define ok "\n"
#define pi pair<int, int>

struct aaa {
	int num, pts, grp;
	bool operator<(aaa const& o) {
		if (o.grp == grp) {
			if (o.pts == pts) {
				return num < o.num;
			}
			else {
				return pts > o.pts;
			}
		}
		else {
			return grp < o.grp;
		}
	}
};

struct numsort {
	bool operator () (const aaa & one, const aaa & two) {
		return one.num < two.num;
	}
};

const int MN = 10005;
int n, s, k, a, b;
char r;
vector<aaa> hm;


int main() {
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> n >> s;
	for (int i = 1; i <= n / s; i++) {
		for (int j = 1; j <= s; j++) {
			int x;
			cin >> x;
			hm.push_back({ x, 0, i });
		}
	}
	sort(hm.begin(), hm.end(), numsort());
	for (int i = 0; i < ((s - 1) * n) / 2; i++) {
		cin >> a >> b >> r;
		if (r == 'W') {
			hm[a - 1].pts += 3;
		}
		else if (r == 'L') {
			hm[b - 1].pts += 3;
		}
		else {
			hm[a - 1].pts++;
			hm[b - 1].pts++;
		}
	}
	sort(hm.begin(), hm.end());
	cin >> k;
	for (int i = k; i <= n; i += s) {
		cout << hm[i - 1].num << " ";
	}
}