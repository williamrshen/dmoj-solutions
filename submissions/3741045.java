import java.util.Arrays;
import java.util.Scanner;

public class Main {



    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);

        //William
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] height = new int[n];
        int[] cost = new int[n];
        int[] c = new int[k];
        Arrays.fill(c, Integer.MAX_VALUE);
        Arrays.fill(cost, Integer.MAX_VALUE);
        cost[0] = 0;
        for (int i = 0; i < n; i ++) {
            height[i] =  sc.nextInt();
        }
        if (k == 1) {
            int sum = 0;
            for (int i = 1; i < n; i ++) {
                sum += Math.abs(height[i] - height[i-1]);
            }
            System.out.println(sum);
            return;
        }
        for (int i = 1; i < n; i ++) {
            if (i == 1) {
                cost[i] = Math.abs(height[i] - height[i-1]);
            } else if (i == 2) {
                int cost1 = cost[1] + Math.abs(height[i] - height[i - 1]);
                int cost2 = Math.abs(height[i] - height[i - 2]);
                cost[i] = Math.min(cost1, cost2);
            } else {
                for (int j = 1; j <= k; j ++) {
                    if (i-j < 0) break;
//                    c[j-1] = cost[i - j] + Math.abs(height[i] - height[i - j]);
                    cost[i] = Math.min(cost[i], cost[i - j] + Math.abs(height[i] - height[i - j]));
                }
//                int min = Integer.MAX_VALUE;
//                for (int j = 0; j < k; j ++) {
//                    if (c[j] < min) min = c[j];
//                }
//                cost[i] = min;
            }
        }
        System.out.println(cost[n-1]);
    }
}