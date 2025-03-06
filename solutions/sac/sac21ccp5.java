import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {

    static int[] par;
    static int[] sz;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int n = readInt(), q = readInt();
        par = new int[n + 1];
        sz = new int[n + 1];
        Arrays.fill(sz, 1);
        for (int i = 1; i <= n; i ++) par[i] = i;
        for (int i = 1; i <= q; i ++) {
            int x = readInt();
            if (x == 1) {

                int a = readInt(), b = readInt();
                if (find(a) != find(b)) {
                    merge(a, b);
                }

            }
            else {

                int a = readInt();
                System.out.println(sz[find(a)]);

            }
        }
    }

    static int find (int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    static void merge (int x, int y) {
        x = find(x);
        y = find(y);
        par[y] = x;
        sz[x] += sz[y];
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