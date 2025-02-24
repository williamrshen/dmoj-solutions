#include <stdio.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int main() {
    int n = 0, s = 0;
    scanf("%d", &n);
    while (n --) {
        int k; scanf("%d", &k);
        s ^= k;
    }
    printf("%d\n", s);
    return 0;
}