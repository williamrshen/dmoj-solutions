#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <algorithm>

using namespace std;

#define ok "\n"

class team {
public:
    int pts, num, grp;
};

const int MM = 2005;
int n, s;
team teams[MM];

bool cmp(team a, team b) {
    if (a.grp != b.grp) {
        return a.grp < b.grp;
    }
    else {
        if (a.pts != b.pts) {
            return a.pts > b.pts;
        }
        else {
            return a.num < b.num;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n / s; i++) {
        for (int j = 1; j <= s; j++) {
            int x; cin >> x;
            teams[x].pts = 0;
            teams[x].num = x;
            teams[x].grp = i;
        }
    }
    for (int i = 0; i < ((s - 1) * n) / 2; i++) {
        int a, b; char r; cin >> a >> b >> r;
        if (r == 'W') {
            teams[a].pts += 3;
        }
        else if (r == 'L') {
            teams[b].pts += 3;
        }
        else {
            teams[a].pts++;
            teams[b].pts++;
        }
    }
    sort(teams + 1, teams + n + 1, cmp);
    int k; cin >> k;
    cout << teams[k].num;
    for (int i = k + s; i <= n; i += s) {
        cout << " " << teams[i].num;
    }
    cout << ok;
}