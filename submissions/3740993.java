import java.util.Scanner;

public class Main {



    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int n = sc.nextInt();
        int[] height = new int[n];
        int[] cost = new int[n];
        for (int i = 0; i < n; i ++) {
            height[i] =  sc.nextInt();
        }
        for (int i = 1; i < n; i ++) {
            if (i == 1) {
                cost[i] = Math.abs(height[i] - height[i-1]);
            } else {
                int cost1 = cost[i - 1] + Math.abs(height[i] - height[i - 1]);
                int cost2 = cost[i - 2] + Math.abs(height[i] - height[i - 2]);
                cost[i] = Math.min(cost1, cost2);
            }
        }

        System.out.println(cost[n-1]);

    }
}