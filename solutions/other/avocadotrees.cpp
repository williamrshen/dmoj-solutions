#include <iostream>

using namespace std;

int n, q, h;
int heights[1000005], avocados[1000005];
int psa[1000005];
int answer = 0;

int main() {
    cin >> n >> q >> h;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        cin >> avocados[i];
        if (heights[i] > h) {
            avocados[i] = 0;
        }
    }
    psa[0] = avocados[0];
    for (int i = 1; i < n; i++) {
        psa[i] = psa[i - 1] + avocados[i];
    }
    cout << "\n";
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
       
        int newAns = 0;
        if (l == 0) {
            newAns = psa[r];
        }
        else {
            newAns = psa[r] - psa[l - 1];
        }
        answer = max(answer, newAns);
    }
    cout << answer << "\n";
}