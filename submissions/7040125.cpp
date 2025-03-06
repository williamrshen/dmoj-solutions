// mccc5j3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

using namespace std;


#define ll long long
int n, k;
ll m;
ll a[200005];
map<ll, int> idx;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        idx[a[i]] = i;

    }
        int ans = 0;

    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
         if (idx.find(m - t) != idx.end()) {
            if (abs(i - idx[m - t]) >= k) {
                ans++;
            }
        }
    }


    cout << ans << "\n";

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