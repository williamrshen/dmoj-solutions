import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = sc.nextInt();
        int[] prices = new int[101];

        for (int i = 0; i < n; i++) {
            int p = sc.nextInt();
            prices[p]++;
        }

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int maxIndex = 0;
        int minIndex = 0;

        for (int i = 1; i < 101; i++) {
            if (prices[i] == 0) {
                continue;
            }

            if (prices[i] >= max) {
                max = prices[i];
                maxIndex = i;
            }

            if (prices[i] < min) {
                min = prices[i];

                minIndex = i;

            }


        }
        System.out.println(Math.abs(maxIndex - minIndex));

    }
}