import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static final int mn = 100005;
    static int[] a = new int[mn];
    static int[] tree = new int[mn * 4];
    static int n, m, x, y;
    static char c;
    public static void main(String[] args) throws IOException {
        n = readInt();
        m = readInt();
        for (int i = 1; i <= n; i ++) a[i] = readInt();
        build(1, n, 1);
        for (int i = 1; i <= m; i ++) {
            c = readCharacter();
            if (c == 'M') {
                x = readInt() + 1;
                y = readInt();
                update(1, n, x, y, 1);
            }
            else {
                x = readInt() + 1;
                y = readInt() + 1;
                System.out.println(query(1, n, x, y, 1));
            }
        }
    }

    public static void build (int l, int r, int idx) {
        if (l == r) {
            tree[idx] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(l, mid, idx * 2);
        build(mid + 1, r, idx * 2 + 1);
        tree[idx] = Math.min(tree[idx * 2], tree[idx * 2 + 1]);
    }

    public static void update (int l, int r, int x, int val, int idx) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (mid >= x) update(l, mid, x, val, idx * 2);
        else update(mid + 1, r, x, val, idx * 2 + 1);
        tree[idx] = Math.min(tree[idx * 2], tree[idx * 2 + 1]);
    }

    public static int query (int l, int r, int x, int y, int idx) {
        if (r < x || l > y) {
            return Integer.MAX_VALUE;
        }
        if (r <= y && l >= x) {
            return tree[idx];
        }
        int mid = (l + r) / 2;
        int lmin = query(l, mid, x, y, idx * 2);
        int rmin = query(mid + 1, r, x, y, idx * 2 + 1);
        return Math.min(lmin, rmin);
    }


    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}