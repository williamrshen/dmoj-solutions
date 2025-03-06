#include <iostream>

using namespace std;

#define ok "\n"

string s;
int ans = 0;
char f[] = { 'H', 'O', 'N', 'I' };
int idx = 0;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == f[idx]) {
            if (idx == 3) {
                ans++;
                idx = 0;
            }
            else {
                idx++;
            }
        }
    }
    cout << ans << ok;
}