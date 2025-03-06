import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int ans = 0;
        int a[] = new int [n+2];
        int pre[] = new int[n+2];
        int suf[] = new int[n+2];
        
        for (int i = 1; i <= n; i ++) {
            a[i] = sc.nextInt();
            pre[i] = gcd(pre[i - 1], a[i]);
        }
        for (int i = n; i >= 1; i --) {
            suf[i] = gcd(suf[i + 1], a[i]);
        }
        for (int i = 1; i <= n; i ++) {
            ans = Math.max(ans, gcd(pre[i - 1], suf[i + 1]));
        }
        System.out.println(ans);
    }
    
     static int gcd(int n, int m) {
        if (m == 0) {
            return n;
        }
        return gcd(m, n % m);
    }
}