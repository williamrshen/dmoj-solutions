import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static final int MN = 10005;
    static List<Integer>[] adj = new List[MN];
    static boolean[] vis = new boolean[MN];
    static int[] dis = new int[MN];
    public static void main(String[] args) throws IOException {
        int n = ri(), m = ri();
        for (int i = 0; i < MN; i ++) adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i ++) {
            int x = ri(), y = ri();
            adj[x].add(y); adj[y].add(x);
        }
        int k = ri();
        for (int i = 0; i < k; i ++) {
            int x = ri(), y = ri();
            int ok = bfs(x, y);
            if (ok == -1) {
                System.out.println("N");
            }
            else {
                System.out.println("Y " + ok);
            }
        }
        int lol = bfs(1, 2);
        for (int i = 1; i <= n; i ++) {
            if (!vis[1]) {
                System.out.println("N");
                return;
            }
        }
        if (n - 1 == m) {
            System.out.println("Y");
        }
        else {
            System.out.println("N");
        }
    }

    static int bfs (int x, int y) {
        Queue<Integer> q = new LinkedList<>();
        Arrays.fill(vis, false);
        Arrays.fill(dis, -1);
        q.add(x); vis[x] = true; dis[x] = 0;
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int e : adj[c]) {
                if (!vis[e]) {
                    q.add(e);
                    vis[e] = true;
                    dis[e] = dis[c] + 1;
                }
            }
            if (vis[y]) {
                return dis[y];
            }
        }
        return dis[y];
    }


    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static long readLong() throws IOException {
        return Long.parseLong(next());
    }

    static int ri() throws IOException {
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

    static int quickpow(int x, int exp, int mod) {
        //function gets exponents really fast
        if (exp == 0) {
            return 1;
        }
        int t = quickpow(x, exp / 2, mod);
        t = t * t % mod;
        if (exp % 2 == 0) return t;
        return t * x % mod;
    }

    static int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }

    static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    static boolean contains(String[] arr, String target) {
        boolean flag = false;
        if (arr.length > 0) {
            for (int i = 0; i < arr.length; i++) {
                if (arr[i].equals(target)) {
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }

    static boolean prime(int n) {
        if (n <= 1) return false;
        else if (n == 2) return true;
        else if (n % 2 == 0) return false;
        for (int i = 3; i <= Math.sqrt(n); i += 2) {
            if (n % i == 0) return false;
        }
        return true;
    }

    //dsu
    static int find_set(int p[], int d) { //parent array and the target parent you're looking for
        if (d != p[d]) p[d] = find_set(p, p[d]);
        return p[d];
    }

    static void union(int p[], int x, int y) {
        int a = find_set(p, x), b = find_set(p, y);
        p[a] = b;
    }

    public static class edge implements Comparable<edge> {
        int u, v, w;

        edge(int u0, int v0, int w0) {
            u = u0;
            v = v0;
            w = w0;
        }

        public int compareTo(edge x) {
            return w - x.w;
        }
    }
}