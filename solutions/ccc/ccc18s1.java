import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = readInt();
        int[] road = new int[n];
        double[] size = new double[n];
        for (int i = 0; i < n; i ++) {
            road[i] = readInt();
        }
        Arrays.sort(road);
        size[0] = Integer.MAX_VALUE;
        size[n - 1] = Integer.MAX_VALUE;
        for (int i = 1; i < n-1; i ++) {
            double left = Math.abs(road[i] - road[i - 1])/2.0;
            double right = Math.abs(road[i] - road[i + 1])/2.0;
            size[i] = left + right;
        }
        Arrays.sort(size);
        System.out.printf("%.1f\n", size[0]);
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}