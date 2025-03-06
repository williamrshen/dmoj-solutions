// year2017p1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

int q;
deque<pair<int, int>> l;
map<int, int> removed;

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> q;
    for (int i = 0; i < q; i ++) {
        char o; int x;
        cin >> o >> x;
        if (o == 'F') {
            l.push_front({x, i});
        } 
        if (o == 'E') {
            l.push_back({x, i});
        }
        if (o == 'R') {
            removed[x] = i;
        }
    }
    for (auto x : l) {
        if (x.second > removed[x.first]) {
            cout << x.first << "\n";
        }
    }
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