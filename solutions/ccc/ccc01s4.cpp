// ccc01s4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>  

using namespace std;

const int MN = 12;
int n;
struct point {
    double x, y;
} p[MN];

double dist(point a, point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

point cir(point a, point b, point c) {
    double d1 = (b.x * b.x + b.y * b.y - a.x * a.x - a.y * a.y) / 2;
    double d2 = (c.x * c.x + c.y * c.y - a.x * a.x - a.y * a.y) / 2;
    double a1 = b.x - a.x;
    double b1 = b.y - a.y;
    double a2 = c.x - a.x;
    double b2 = c.y - a.y;
    double denom = a1 * b2 - a2 * b1;
    return point{ (d1 * b2 - d2 * b1) / denom, (a1 * d2 - a2 * d1) / denom };
}

double solve() {
    random_shuffle(p, p + n);
    point cen = p[0];
    double r = 0;
    for (int i = 1; i < n; i ++) {
        if (dist(cen, p[i]) > r) {
            cen = p[i]; r = 0;
                for (int j = 0; j < i; j++) {
                    if (dist(cen, p[j]) > r) {
                        cen = point{(p[i].x + p[j].x) / 2, (p[i].y + p[j].y) / 2};
                        r = dist(cen, p[i]);
                        for (int k = 0; k < j; k++) {
                            if (dist(cen, p[k]) > r) {
                                cen = cir(p[i], p[j], p[k]);
                                r = dist(cen, p[i]);
                            }
                        }
                    }
                }
        }
    }
    return r;
}

int main()
{
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    cout << fixed << setprecision(2) << 2 * solve() << "\n";
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