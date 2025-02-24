// macs1p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

const int MN = 1e5;
int n;
vector<int> a;

vector<int> solve(vector<int> x) {
    if (x.size() == 1) {
        return x;
    }
    else {
        int sz = x.size() / 3;
        vector<int> v1, v2, v3;
        for (int i = 0; i < sz; i++) v1.push_back(x[i]);
        for (int i = sz; i < 2 * sz; i++) v2.push_back(x[i]);
        for (int i = 2 * sz; i < 3 * sz; i ++) v2.push_back(x[i]);
        solve(v1); solve(v2); solve(v3);
        vector<int> v4;
        for (int i = 0; i < sz; i++) v4.push_back(v3[i]);
        for (int i = 0; i < sz; i++) v4.push_back(v1[i]);
        for (int i = 0; i < sz; i++) v4.push_back(v2[i]);
        return v4;
    }
}

void f(int l, int r) {
    if (l == r) {
        cout << a[r] << " ";
        return;
    }
    int sz = (r - l + 1) / 3;
    f(l + 2 * sz, r);
    f(l, l + sz - 1);
    f(l + sz, l + 2 * sz - 1);
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    // vector<int> out = solve(a);
    f(0, n - 1);
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