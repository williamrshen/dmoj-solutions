#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m;
vector<long long>vec;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        vec.push_back(a);
        m += a;
    }
    sort(vec.begin(), vec.end());
    m -= *(vec.end() -  1);
    cout << m;
}