// daacc1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string e;
int n, out;

int main()
{
    cin >> e >> n;
    for (int i = 0; i < n; i++) {
        int dmg; string t;
        cin >> dmg >> t;
        if (e == "FIRE") {
            if (t == "FIRE") {
                out = max(out, dmg);
            }
            else if (t == "GRASS") {
                out = max(out, dmg / 2);
            }
            else {
                out = max(out, dmg * 2);
            }
        } else if (e == "WATER") {
            if (t == "WATER") {
                out = max(out, dmg);
            }
            else if (t == "FIRE") {
                out = max(out, dmg / 2);
            }
            else {
                out = max(out, dmg * 2);
            }
        }
        else if (e == "GRASS") {
            if (t == "GRASS") {
                out = max(out, dmg);
            }
            else if (t == "WATER") {
                out = max(out, dmg / 2);
            }
            else {
                out = max(out, dmg * 2);
            }
        }
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