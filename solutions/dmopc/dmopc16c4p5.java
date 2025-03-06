import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int[] par;
    static int[] ans;
    static ArrayList<edge> edges;
    static ArrayList<Integer>[] nodes;
    static boolean[] has1 = new boolean[200005];
    public static void main(String[] args) throws IOException {

        int n = readInt(), m = readInt();
        par = new int[200005];
        ans = new int[200005];
        nodes = new ArrayList[200005];
        edges = new ArrayList<>();
        has1[1] = true;
        for (int i = 1; i < 200005; i ++) {
            nodes[i] = new ArrayList<>();
            par[i] = i;
            nodes[i].add(i);
        }
        for (int i = 1; i <= m; i ++) {
            int u = readInt(), v = readInt(), w = readInt();
            edges.add(new edge(u, v, w));
        }
        Collections.sort(edges);
        for (edge k : edges) {
            int x = find(k.u), y = find(k.v);
            if (x != y) {
                merge(k.u, k.v, k.w);
            }
        }
        for (int i = 1; i <= n; i ++) System.out.println(ans[i]);

    }

    static class edge implements Comparable<edge> {
        int u, v, w;
        public edge (int a, int b, int c) {
            u = a;
            v = b;
            w = c;
        }
        public int compareTo(edge o) {
            return o.w - this.w;
        }
    }

    static int find (int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    static void merge(int x, int y, int z) {

        x = find(x); y = find(y);
        if (nodes[x].size() > nodes[y].size()) {
            int temp = x;
            x = y;
            y = temp;
        }
        if (has1[x]) for (int a: nodes[y]) ans[a] = z;
        else if (has1[y]) for (int a: nodes[x]) ans[a] = z;

        for (int a : nodes[x]) nodes[y].add(a);
        par[x] = y;
        has1[y] |= has1[x];
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