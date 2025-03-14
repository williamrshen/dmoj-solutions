#include <bits/stdc++.h>
using namespace std;

typedef unsigned uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef complex<double> cmplx;
template <typename T> using minPq = priority_queue<T, vector<T>, greater<T>>;
#define boost() cin.sync_with_stdio(0); cin.tie(0)
#define ms(a, x) memset(a, x, sizeof(a))
#define pb push_back
#define eb emplace_back
#define fs first
#define sn second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int) (v).size())
#define lbv(v, x) (lower_bound((v).begin(), (v).end(), x) - (v).begin())
#define ubv(v, x) (upper_bound((v).begin(), (v).end(), x) - (v).begin())
template <typename T> inline void UNIQUE(vector<T> &v){sort(ALL(v)); v.resize(unique(ALL(v)) - v.begin());}
inline constexpr int lg2(int x){return 32 - __builtin_clz(x);} // Num used bits
inline constexpr ll lg2(ll x){return 64 - __builtin_clzll(x);} // Num used bits
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

const int MN = 1e5 + 5;
int n;
vi adjList[MN];
int deg[MN];
int arr[MN], ans[MN];

int main(){
    boost();
    cin >> n;
    queue<int> qu;

    for (int i = 0; i < n; i++) {
        cin >> arr[i] >> deg[i];
        if(deg[i] == 0){
            ans[i] = arr[i];
            qu.push(i);
        }

        for (int j = 0; j < deg[i]; j++) {
            int a; cin >> a; a--;
            adjList[a].pb(i);
        }
    }

    int total = 0;
    while(!qu.empty()){
        int n1 = qu.front(); qu.pop();
        total = max(total, ans[n1]);

        for(int n2 : adjList[n1]){
            ans[n2] = max(ans[n2], ans[n1]);
            if(--deg[n2] == 0){
                ans[n2] += arr[n2];
                qu.push(n2);
            }
        }
    }

    cout << total << '\n';
}