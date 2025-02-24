import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int[] s = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i ++) {
            s[i] = readInt();
            sum += s[i];
        }
        int a = sum/n;
        int ans = 0;
        for (int x : s) {
            if (x != a) ans ++;
        }
        System.out.println(ans);
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