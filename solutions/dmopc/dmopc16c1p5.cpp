// dmopc16c1p5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define int long long 

const int MN = 5e5 + 5;
int n, bit[MN], out;

void upd(int pos, int val) {
    for (int i = pos; i < MN; i += i & -i) {
        bit[i] += val;
    }
}

int qry(int pos) {
    int ret = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ret += bit[i];
    }
    return ret;
}

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int s = qry(x), b = i - 1 - s;
        out += min(s, b);
        upd(x, 1);
    }
    cout << out << "\n";
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