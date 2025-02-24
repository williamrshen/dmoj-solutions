import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
//        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = sc.nextInt();
        int[] frequency = new int[101];

        for (int i = 0; i < n; i++) {
            int p = sc.nextInt();
            frequency[p]++;
        }

        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int maxIndex = 0;
        int minIndex = 0;

        for (int i = 1; i < 101; i++) {
            if (frequency[i] == 0) {
                continue;
            }

            if (frequency[i] >= max) {
                max = frequency[i];
                maxIndex = i;
            }

            if (frequency[i] < min) {
                min = frequency[i];

                minIndex = i;

            }


        }
        System.out.println(Math.abs(maxIndex - minIndex));

    }
}