/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define ok "\n"

const int MN = 1e7 + 5;
int n, q, k, a[MN], x;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    while (q--) {
        cin >> x;
        a[x] ++;
        if (a[x] == k + 1) {
            a[x] = 1;
        }
    }
    
    for (int i = 1; i <= n; i ++) {
        cout << a[i] << " \n"[i == n];
    }

    return 0;
}