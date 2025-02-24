import java.io.IOException;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        int[] weight = new int[n+1];
        int[] value = new int[n+1];

        long[][] memo = new long[n+1][w+1];

        for (int i = 0; i < n; i ++) {
            weight[i] = sc.nextInt();
            value[i] = sc.nextInt();
        }

        for (int r = 0; r <= n; r ++) {
            for (int c = 0; c <= w; c ++) {
                if (r == 0 || c == 0) {
                    memo[r][c] = 0;
                } else {
                    if (weight[r - 1] <= c) {
                        memo[r][c] = Math.max(memo[r-1][c], value[r - 1] + memo[r - 1][(c - weight[r-1])]);
                    } else {
                        memo[r][c] = memo[r - 1][c];
                    }
                }
            }
        }
        System.out.println(memo[n][w]);
    }
}