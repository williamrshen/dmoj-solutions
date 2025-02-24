// ccc21s4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MN = 2e5 + 5;
int n, w, d, walk[MN], train[MN], route[MN];
bool vis[MN];
queue<int> q;
vector<int> adj[MN];

struct node {
    int l, r, v;
} seg[MN * 4];

void build(int l, int r, int rt) {
    seg[rt].l = l;
    seg[rt].r = r;
    if (l == r) {
        seg[rt].v = walk[l] + train[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * rt);
    build(mid + 1, r, 2 * rt + 1);
    seg[rt].v = min(seg[2 * rt].v, seg[2 * rt + 1].v);
}

void upd(int idx, int val, int rt) {
    if (seg[rt].l == seg[rt].r) {
        seg[rt].v = val;
        return;
    }
    int mid = (seg[rt].l + seg[rt].r) / 2;
    if (idx <= mid) {
        upd(idx, val, 2 * rt);
    }
    else {
        upd(idx, val, 2 * rt + 1);
    }
    seg[rt].v = min(seg[2 * rt].v, seg[2 * rt + 1].v);
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> w >> d;
    for (int i = 1; i <= w; i++) {
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }
    memset(walk, 0x3f, sizeof(walk));
    walk[n] = 0; vis[n] = 1; q.push(n);
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int x : adj[cur]) {
            if (!vis[x]) {
                vis[x] = 1;
                q.push(x);
                walk[x] = walk[cur] + 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> route[i];
        train[route[i]] = i - 1;
    }
    build(1, n, 1);
    for (int i = 1; i <= d; i++) {
        int a, b; cin >> a >> b;
        int pa = route[a], pb = route[b];
        swap(train[pa], train[pb]);
        swap(route[a], route[b]);
        upd(pa, walk[pa] + train[pa], 1);
        upd(pb, walk[pb] + train[pb], 1);
        cout << seg[1].v << "\n";
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