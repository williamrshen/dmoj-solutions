#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename C,typename T=typename enable_if<!is_same<C,string>::value,typename C::value_type>::type>
ostream& operator<<(ostream&os,const C&v){os<<"[";bool f=1;for(const T&x:v){if(!f)os<<", ";os<<x;f=0;}return os<<"]";}
template<typename T1,typename T2>
ostream& operator<<(ostream&os,const pair<T1,T2>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
#define nl '\n'
#ifndef DEBUG_393939
#define cerr while (0) cerr
static const int __39 = [](){ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 39;}();
#endif
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T&& fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args>
    decltype(auto) operator()(Args&& ...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
template<class T> T& setmin(T& tgt, const T& src) { return (tgt = min(tgt, src)); }
template<class T> T& setmax(T& tgt, const T& src) { return (tgt = max(tgt, src)); }
const uint64_t RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
constexpr uint64_t HASH_C = 0x57325bbf44649447; // large odd number for C; ll(4e18 * acos(0)) | 71
struct chash {
    ll operator()(ll x) const { return __builtin_bswap64((x ^ RANDOM) * HASH_C); }
    ll operator()(pii x) const { return operator()((ll(x.first) << 32) | x.second); }
};

int main() {
    int n;
    cin >> n;
    vector<vi> graph(n);
    vi time(n);
    rep(i, 0, n) {
        int t, r;
        cin >> t >> r;
        time[i] = t;
        rep(j, 0, r) {
            int x;
            cin >> x;
            x--;
            graph[i].push_back(x);
        }
    }
    vector<ll> res(n, -1);
    vector<bool> visited(n);
    vector<bool> alive(n);
    auto dfs = y_combinator([&](auto self, int u, int _par) -> void {
        if (alive[u]) {
            visited[u] = true;
            return;
        }
        if (visited[u]) return;
        alive[u] = true;
        ll t = 0;
        visited[u] = true;
        for (int v : graph[u]) {
            self(v, u);
            if (res[v] != -1) {
                t = max(t, res[v]);
            } else {
                t = -1;
                break;
            }
        }
        if (t != -1) {
            res[u] = t + time[u];
        }
        alive[u] = false;
    });
    rep(i, 0, n) {
        dfs(i, -1);
    }
    ll ans = 0;
    rep(i, 0, n) {
        if (res[i] != -1) ans = max(ans, res[i]);
    }
    cout << ans << nl;
    return 0;
}