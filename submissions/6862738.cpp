// 2023J3 - Special Event.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
int n;
string person;
int max_day = 0;
vector<int> avail(5), days;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> person;
        for (int j = 0; j < 5; j++) {
            if (person[j] == 'Y') {
                avail[j]++;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        if (avail[i] > max_day) {
            max_day = avail[i];
        }
    }
    for (int i = 0; i < 5; i++) {
        if (avail[i] == max_day) {
            days.push_back(i + 1);
        }
    }
    for (int i = 0; i < days.size(); i++) {
        cout << days[i];
        cout << ((i != days.size() - 1) ? "," : "\n");
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