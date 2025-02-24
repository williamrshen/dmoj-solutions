import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        int n = readInt();
        Long d = readLong();
        int k = readInt();
        int x = readInt();
        double speed[] = new double [n + 1];
        for (int i = 1; i <= n; i ++) {
            speed[i] = Long.parseLong(br.readLine());
        }
        long p = readLong();
        double factor = (double)(100 - x)/100;
        int count = 0;
        for (int i = 1; i <= n; i ++) {
            while (count <= k && speed[i] >= p) {
                speed[i] = Math.floor(speed[i]*factor);
                count ++;
            }
        }
        if (count <= k) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }

    }

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
    static long readLong() throws IOException {
        return Long.parseLong(next());
    }
}