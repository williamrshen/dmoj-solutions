import java.io.IOException;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int w = sc.nextInt();
        int[] weight = new int[n+1];
        int[] value = new int[n+1];

        long[][] memo = new long[2][w+1];

        for (int i = 0; i < n; i ++) {
            weight[i] = sc.nextInt();
            value[i] = sc.nextInt();
        }

        for (int r = 0; r <= n; r ++) {
            for (int c = 0; c <= w; c ++) {
                int row = r%2;
                if (r == 0 || c == 0) {
                    memo[row][c] = 0;
                } else {
                    if (row == 0) {
                        if (weight[r - 1] <= c) {
                            memo[row][c] = Math.max(memo[row + 1][c], value[r - 1] + memo[row + 1][(c - weight[r - 1])]);
                        } else {
                            memo[row][c] = memo[row + 1][c];
                        }
                    } else {
                        if (weight[r - 1] <= c) {
                            memo[row][c] = Math.max(memo[row - 1][c], value[r - 1] + memo[row - 1][(c - weight[r - 1])]);
                        } else {
                            memo[row][c] = memo[row - 1][c];
                        }
                    }
                }
            }
        }
        System.out.println(memo[n%2][w]);
    }
}