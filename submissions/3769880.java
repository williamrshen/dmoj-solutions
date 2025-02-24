import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int n = readInt();
        double area = 0;
        int[] h = new int[n + 1];
        int[] w = new int[n];

        for (int i = 0; i < n + 1; i ++) {
            h[i] = readInt();
        }
        for (int i = 0; i < n; i ++) {
            w[i] = readInt();
        }
        for (int i = 0; i < n; i ++) {
            double avg = ((double)h[i] + (double)h[i + 1])/2;
            area += w[i]*avg;
        }
        String[] ok = String.valueOf(area).split("\\.");
        if (ok[1].equals("0")) System.out.println(ok[0]);
        else System.out.println(area);
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}