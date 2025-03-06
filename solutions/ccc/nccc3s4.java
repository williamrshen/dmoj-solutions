import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int n = readInt();
        long sum = 0;
        long max = -1;
        for (int i = 0; i < n; i ++) {
            int x = readInt();
            sum += x;
            if (x > max) max = x;
        }
        if (sum % 2 == 0 && sum - max >= max) System.out.println("YES");
        else System.out.println("NO");
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