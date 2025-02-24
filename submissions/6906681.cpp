// dmopc21c4p2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MJ 5000005
int n, cnt;
vector<int> js;
bool group[MJ];

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        js.push_back(x);
    }
    sort(js.begin(), js.end());
    for (int i = 0; i < n; i++) {
        if (!group[js[i]]) {
            cnt++;
            for (int j = js[i]; j < MJ; j += js[i]) {
                group[j] = true;
            }
        }
    }
    cout << cnt << "\n";
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