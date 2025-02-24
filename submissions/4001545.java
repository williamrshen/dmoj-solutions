import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = sc.nextInt();
        int m = sc.nextInt();
        int max = (int) 5e6+1;
        int limit = (int) 4e4+1;
        boolean a[] = new boolean[max];
        List<Integer> prime = new ArrayList();
        for (int i = 2; i <= limit; i ++) {
            if (!a[i]) {
                prime.add(i);
                for (int j=2*i; j <= limit; j += i) {
                    a[j] = true;
                }
            }
        }
        Arrays.fill(a, false);
        for (int x: prime) {
            for (int i = n - n % x; i <= m; i += x) {
                if (i >= n && i != x) {
                    a[i - n] = true;
                }
            }
        }
        for (int i = n; i <= m; i ++) {
            if (i > 1 && !a[i - n]) {
                System.out.println(i);
            }
        }
    }
}