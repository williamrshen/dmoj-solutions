// coci10c3p5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;

#define ok "\n"

const int MN = 3e5 + 5;
int n, a[MN];
stack<int> mx, mi;
long long cntmx[MN], cntmi[MN], out;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        while (mx.size() and a[mx.top()] <= a[i]) {
            int id = mx.top();
            cntmx[id] *= i - id;
            mx.pop();
        }
        while (mi.size() and a[mi.top()] >= a[i]) {
            int id = mi.top();
            cntmi[id] *= i - id;
            mi.pop();
        }
        int x = mx.empty() ? 0 : mx.top();
        cntmx[i] = i - x;
        x = mi.empty() ? 0 : mi.top();
        cntmi[i] = i - x;
        mx.push(i);
        mi.push(i);
    }
    while (mx.size()) {
        int id = mx.top();
        cntmx[id] *= n + 1 - id;
        mx.pop();
    }
    while (mi.size()) {
        int id = mi.top();
        cntmi[id] *= n + 1 - id;
        mi.pop();
    }
    for (int i = 1; i <= n; i++) {
        out += (cntmx[i] - cntmi[i]) * a[i];
    }
    cout << out << ok;
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