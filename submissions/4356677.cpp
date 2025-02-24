#undef NDEBUG

#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;
typedef double f64;
typedef int8_t flag;

const i64 MOD = 1000000007;
const i64 INF = 0x3f3f3f3f3f3f3f3f;

struct Event {
  i64 time;
  vector<i64> prereq;
};
void dfs(i64 u, const vector<Event> &events, vector<i64> &total_time,
         vector<flag> &visited) {
  if (visited[u]) {
    return;
  }
  visited[u] = 1;
  i64 max_child_time = 0;
  for (i64 v : events[u].prereq) {
    dfs(v, events, total_time, visited);
    max_child_time = max(max_child_time, total_time[v]);
  }
  if (max_child_time < INF) {
    total_time[u] = max_child_time + events[u].time;
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  i64 n;
  cin >> n;
  vector<Event> events(n + 1);
  for (i64 i = 1; i <= n; ++i) {
    i64 r;
    cin >> events[i].time >> r;
    events[i].prereq.resize(r);
    for (i64 j = 0; j < r; ++j) {
      cin >> events[i].prereq[j];
    }
  }

  vector<i64> total_time(n + 1, INF);
  vector<flag> visited(n + 1);
  for (i64 u = 1; u <= n; ++u) {
    dfs(u, events, total_time, visited);
  }

  i64 max_time = 0;
  for (i64 t : total_time) {
    if (t != INF) {
      max_time = max(max_time, t);
    }
  }
  cout << max_time << '\n';
  return 0;
}