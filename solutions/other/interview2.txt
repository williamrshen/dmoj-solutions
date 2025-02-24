import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        Set<Integer> s = new HashSet<>();
        Set<String> ss = new HashSet<>();
        int n = readInt(), a[] = new int[n];
        for (int i = 0; i < n; i ++) {
            int x = readInt(); a[i] = x; s.add(x);
        }
        for (int i = n - 1; i >= 0; i --) {
            for (int j = 0; j < i; j ++) {
                if (s.contains(a[i] + a[j])) {
                    String add = "";
                    if (a[i] > a[j]) {
                        add += a[j];
                        add += a[i];
                    } else {
                        add += a[i];
                        add += a[j];
                    }
                    add += a[i] + a[j];
                    ss.add(add);
                }
            }
        }
        if (ss.isEmpty()) System.out.println(-1);
        else System.out.println(ss.size());
    }


    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}