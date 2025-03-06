import java.util.*;
import java.io.*;
public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{

        int n = readInt();
        List<Integer>[] adj = new ArrayList[10000];
        for (int i = 1; i <= 9999; i ++) adj[i] = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            int x = readInt(), y = readInt();
            adj[x].add(y);
        }

        while (true) {
            int x = readInt(), y = readInt();
            if (x == 0 && y == 0) return;
            boolean[] v = new boolean[10000];
            Arrays.fill(v, false);
            int ans = -1;
            while (!v[x] && x != y) {
                v[x] = true;
                ans ++;
                x = adj[x].get(0);
            }
            if (x == y) System.out.println("Yes " + ans);
            else System.out.println("No");
        }
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