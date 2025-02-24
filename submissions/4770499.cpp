// dmpg16s5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>

using namespace std;

#define int long long

const int MN = 100005;

int n, k, psa[MN * 2], out;
deque<int> q;

int32_t main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> psa[i];
        psa[i + n] = psa[i];
    }
    q.push_back(0);
    for (int i = 1; i <= 2 * n; i++) {
        psa[i] += psa[i - 1];
        if (q.size() and q.front() < i - k) {
            q.pop_front();
        }
        while (q.size() and psa[i] <= psa[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
        out = max(out, psa[i] - psa[q.front()]);
    }
    cout << out << endl;
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