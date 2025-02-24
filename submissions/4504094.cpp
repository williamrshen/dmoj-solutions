#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdio.h>

using namespace std;

#define ok "\n"
#define int long long

const int MN = 1000005;
int n, arr[MN], out, b;

int32_t main() {
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        b = max(arr[i], b);
        arr[i] += arr[i - 1];
    }
    for (int i = 1; i <= b; i++) {
        vector<int> v;
        v.push_back(0);
        for (int j = 1; j <= n; j++) {
            v.push_back(arr[j] - j * i);
        }
        sort(v.begin(), v.end());
        v.push_back(99999999);
        int c = 1;
        for (int j = 1; j < v.size(); j++) {
            if (v[j] != v[j - 1]) {
                out += c * (c - 1) / 2;
                c = 1;
            }
            else {
                c++;
            }
        }
    }
    cout << out << ok;
}