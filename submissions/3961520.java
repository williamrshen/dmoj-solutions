import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int n = readInt();
        long ans = 1;
        int[] c = new int[n];
        int[] s = new int[n];
        for (int i = 0; i < n; i ++) c[i] = readInt();
        for (int i = 0; i < n; i ++) s[i] = readInt();
        Arrays.sort(c);
        Arrays.sort(s);
        for (int i = n - 1; i >= 0; i --) {
            int count = 0;
            for (int j = i; j >= 0; j --) {
                if (s[j] >= c[i]) count ++;
            }
            ans *= count;
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