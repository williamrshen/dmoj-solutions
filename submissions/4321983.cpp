#include <iostream>

using namespace std;

#define ok "\n"

const int MN = 0;
string ans[3];
string gus[3];
int g = 0, y = 0;
int fa[26], fg[26];

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> ans[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> gus[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (ans[i][j] == gus[i][j]) {
                g++;
                fa[ans[i][j] - 'A'] --;
                fg[ans[i][j] - 'A'] --;
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fa[ans[i][j] - 'A'] ++;
            fg[gus[i][j] - 'A'] ++;
        }
    }
    //for (int i = 0; i < 26; i++) {
    //    cout << fa[i] << " ";
    //}
    //cout << ok;
    //for (int i = 0; i < 26; i++) {
    //    cout << fg[i] << " ";
    //}
    //cout << ok;
    for (int i = 0; i < 26; i++) {
        if (fa[i] <= fg[i]) {
            if (fa[i] >= 0) {
                y += fa[i];
            }
        }
        if (fa[i] > fg[i]) {
            y += fg[i];
        }
    }
    cout << g << ok << y << ok;
}