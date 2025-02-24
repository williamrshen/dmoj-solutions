import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static boolean[][] adj;
    static int[] one;
    static int[] two;
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int[] h = new int[n];
        for (int i = 0; i < n; i ++) h[i] = readInt();
        int ans = 0;
        int anscost = Integer.MAX_VALUE;
        for (int i = -100; i <= 100; i ++) {
            int cost = 0;
            for (int x : h) {
              cost += Math.pow(x - i, 2);
            }
            if(cost < anscost) {
              anscost = cost;
              ans = i;
            }
        }
        System.out.println(anscost);
        
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }

    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static char readCharacter() throws IOException {
        return next().charAt(0);
    }

    static String readLine() throws IOException {
        return br.readLine().trim();
    }

}