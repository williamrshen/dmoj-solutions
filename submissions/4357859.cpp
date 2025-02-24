#include <bits/stdc++.h>
using namespace std;
template <class C> constexpr int sz(const C &c) { return int(c.size()); }
constexpr const char nl = '\n', sp = ' '; using uint = unsigned int;
using ll = long long; using ull = unsigned long long; using ld = long double;
#if __SIZEOF_INT128__
  using i128 = __int128_t; using ui128 = __uint128_t;
#endif

namespace Validator {
  std::regex nonWhitespaceChar("\\S");
  bool _hasLast = false;
  char _last;

  char _peekChar() {
    _last = _hasLast ? _last : getchar();
    _hasLast = true;
    return _last;
  }

  char _getChar() {
    char ret = _peekChar();
    _hasLast = false;
    return ret;
  }

  long long readInt(long long minValid = std::numeric_limits<long long>::min(), long long maxValid = std::numeric_limits<long long>::max()) {
    std::string token = "";
    while (isdigit(_peekChar()) || _peekChar() == '-') token.push_back(_getChar());
    long long ret = std::stoll(token);
    assert(minValid <= ret && ret <= maxValid);
    return ret;
  }

  long double readFloat(long double minValid = std::numeric_limits<long double>::lowest(), long double maxValid = std::numeric_limits<long double>::max()) {
    std::string token = "";
    while (isdigit(_peekChar()) || _peekChar() == '-' || _peekChar() == '.') token.push_back(_getChar());
    long double ret = std::stold(token);
    assert(minValid <= ret && ret <= maxValid);
    return ret;
  }

  std::string readString(const std::regex &rgx) {
    std::string ret = "";
    while (!isspace(_peekChar())) ret.push_back(_getChar());
    assert(std::regex_match(ret, rgx));
    return ret;
  }

  std::string readString() {
    std::string ret = "";
    while (!isspace(_peekChar())) ret.push_back(_getChar());
    return ret;
  }

  char readChar(const std::regex &rgx = nonWhitespaceChar) {
    char ret = _getChar();
    assert(std::regex_match(std::string(1, ret), rgx));
    return ret;
  }

  std::string readLine(const std::regex &rgx) {
    std::string ret = "";
    while (_peekChar() != '\n') ret.push_back(_getChar());
    assert(std::regex_match(ret, rgx));
    return ret;
  }

  std::string readLine() {
    std::string ret = "";
    while (_peekChar() != '\n') ret.push_back(_getChar());
    return ret;
  }

  void readSpace() {
    assert(_getChar() == ' ');
  }

  void readNewLine() {
    assert(_getChar() == '\n');
  }

  void readEOF() {
    assert(_getChar() == std::char_traits<char>::eof());
  }
}

using namespace Validator;

struct StaticGraph {
  vector<int> ST, TO, A, B; StaticGraph(int V) : ST(V + 1, 0) {}
  void reserveDiEdges(int maxEdges) {
    TO.reserve(maxEdges); A.reserve(maxEdges); B.reserve(maxEdges);
  }
  void addDiEdge(int from, int to) {
    ST[from]++; A.push_back(from); B.push_back(to);
  }
  void addBiEdge(int v, int w) { addDiEdge(v, w); addDiEdge(w, v); }
  void build() {
    partial_sum(ST.begin(), ST.end(), ST.begin()); TO = B;
    for (int e = 0; e < int(A.size()); e++) TO[--ST[A[e]]] = B[e];
  }
  struct Iterator {
    const StaticGraph &G; int i;
    Iterator(const StaticGraph &G, int i) : G(G), i(i) {}
    Iterator &operator ++ () { i++; return *this; }
    int operator * () const { return G.TO[i]; }
    bool operator != (const Iterator &it) const { return i != it.i; }
  };
  struct Adj {
    const StaticGraph &G; int v;
    Adj(const StaticGraph &G, int v) : G(G), v(v) {}
    const Iterator begin() const { return Iterator(G, G.ST[v]); }
    const Iterator end() const { return Iterator(G, G.ST[v + 1]); }
  };
  const Adj operator [] (int v) const { return Adj(*this, v); }
  int size() const { return int(ST.size()) - 1; }
};

struct SCC {
  int ind, top; vector<int> id, low, stk; vector<vector<int>> components;
  int getTo(int e) { return e; }
  template <class T> int getTo(const pair<int, T> &e) { return e.first; }
  template <class Digraph> void dfs(const Digraph &G, int v) {
    id[stk[top++] = v] = -1; int mn = low[v] = ind++; for (auto &&e : G[v]) {
      int w = getTo(e); if (id[w] == -2) dfs(G, w);
      mn = min(mn, low[w]);
    }
    if (mn < low[v]) { low[v] = mn; return; }
    int w; components.emplace_back(); do {
      id[w = stk[--top]] = components.size() - 1; low[w] = INT_MAX;
      components.back().push_back(w);
    } while (w != v);
  }
  template <class Digraph> SCC(const Digraph &G)
      : ind(0), top(0), id(G.size(), -2), low(G.size()), stk(G.size()) {
    for (int v = 0; v < int(G.size()); v++) if (id[v] == -2) dfs(G, v);
  }
  template <class Digraph>
  SCC(const Digraph &G, vector<pair<int, int>> &condensationEdges) : SCC(G) {
    vector<int> last(components.size(), -1);
    for (auto &&comp : components) for (int v : comp) for (auto &&e : G[v]) {
      int w = getTo(e); if (id[v] != id[w] && last[id[w]] != id[v])
        condensationEdges.emplace_back(last[id[w]] = id[v], id[w]);
    }
  }
};

int main() {
  int N = readInt(1, 6001);
  readNewLine();
  StaticGraph G(N);
  vector<int> T(N), q(N), inDeg(N), dist(N, 0);
  int front = 0, back = 0;
  for (int i = 0; i < N; i++) {
    T[i] = readInt(1, 1e4);
    readSpace();
    inDeg[i] = readInt(0, N - 1);
    if (inDeg[i] == 0) {
      q[back++] = i;
      dist[i] = T[i];
    }
    for (int j = 0; j < inDeg[i]; j++) {
      readSpace();
      int k = readInt(1, N) - 1;
      assert(k != i);
      G.addDiEdge(k, i);
    }
    readNewLine();
  }
  readEOF();
  G.build();
  SCC scc(G);
  vector<bool> inCycle(N, false);
  for (auto &&comp : scc.components) if (sz(comp) > 1) for (int v : comp) inCycle[v] = true;
  while (front < back) {
    int v = q[front++];
    for (int w : G[v]) if (!inCycle[w]) {
      if (--inDeg[w] == 0) q[back++] = w;
      dist[w] = max(dist[w], dist[v] + T[w]);
    }
  }
  cout << *max_element(dist.begin(), dist.end()) << nl;
  return 0;
}