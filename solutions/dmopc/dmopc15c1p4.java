import java.util.*;
import java.io.*;

public class Main {


    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int x = sc.nextInt();
        boolean[] a = new boolean[n+1];

        for (int k = 2; k <= n; k ++) {
            a[k] = true;
        }

        for (int i = 2; i <= Math.sqrt(n); i ++) {
            if (a[i]) {
                for (int j=i*i; j <= n; j += i) {
                    a[j] = false;
                }
            }
        }

        int ways = 0;
        for (int f =2; f <= n; f ++) {
            if (a[f]) {
                ways += (n-f)/x+1;
                if (n-f-1 >= 0) {
                    ways += (n-f-1)/x+1;
                }
            }
        }
        System.out.println(ways);

    }

}