// class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

int days;
int avail[5];
vector<int> ans;

int main()
{
    cin >> days;
    for (int i = 0; i < days; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++) {
            if (s[j] == 'Y') {
                avail[j]++;
            }
        }
    }

    int max = 0;
    for (int i = 0; i < 5; i++) {
        if (max < avail[i]) {
            max = avail[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        if (avail[i] == max) {
            ans.push_back(i + 1);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) {
            cout << ",";
        }
        else {
            cout << endl;
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