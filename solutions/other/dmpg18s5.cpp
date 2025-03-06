#include <stdio.h>
#include <math.h>
#include <vector>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

vector<int> factorize(int n) {
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ans.push_back(i);
            if (n / i != i) {
                ans.push_back(n / i);
            }
        }
    }
    return ans;
}

int main() {
    int n, q;
    scan(n);
    scan(q);
    int arr[n], rt = sqrt(n) + 5;
    vector<vector<int>> cnt(sqrt(n) + 5, vector<int>(200001));
    for (int i = 0; i < n; i++) {
        scan(arr[i]);
        vector<int> factors = factorize(arr[i]);
        int temp = i / rt;
        for (int factor : factors) {
            cnt[temp][factor]++;
        }
    }
    for (int i = 0; i < q; i++) {
        int query;
        scan(query);
        if (query == 1) {
            int l, r, x, ans = 0;
            scan(l);
            scan(r);
            scan(x);
            l--;
            while (l % rt && l != r) {
                if (arr[l] % x == 0) {
                    ans++;
                }
                l++;
            }
            if (l == r) {
                printf("%d\n", ans);
                goto endd;
            }
            while (r % rt) {
                if (arr[r - 1] % x == 0) {
                    ans++;
                }
                r--;
            }
            for (int i = l / rt; i < r / rt; i++) {
                ans += cnt[i][x];
            }
            printf("%d\n", ans);
        } else {
            int u, v;
            scan(u);
            scan(v);
            u--;
            int temp = u / rt;
            vector<int> factors = factorize(arr[u]);
            for (int factor : factors) {
                cnt[temp][factor]--;
            }
            arr[u] = v;
            factors = factorize(v);
            for (int factor : factors) {
                cnt[temp][factor]++;
            }
        }
        endd:;
    }
}