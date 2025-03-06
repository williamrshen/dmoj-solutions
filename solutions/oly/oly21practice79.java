import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {

    static int[] par;
    static int[] sz;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int n = readInt();
        Map<Integer, Integer> m = new TreeMap<>();
        for (int i = 0; i < n; i ++) {
            int x = readInt();
            if (m.get(x) == null) {
                m.put(x, 1);
            }
            else {
                int a = m.get(x);
                m.put(x, a + 1);
            }
        }
        int max = 0;
        int ans = 0;
        for (int x : m.keySet()) {
            if (m.get(x) > max) {
                max = m.get(x);
                ans = x;
            }
        }
        System.out.println(ans);
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