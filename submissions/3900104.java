import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int ans = Integer.MAX_VALUE;
    static int[] sour;
    static int[] bit;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        sour = new int[n + 1];
        bit = new int[n + 1];
        for (int i = 1; i <= n; i ++) {
            sour[i] = readInt();
            bit[i] = readInt();
        }
        List<Integer> c = new ArrayList<>();
        r(1, n ,c);
        System.out.print(ans);
    }
    static void r(int i, int n, List<Integer> c) {
        if (i > n) {
            if (c.isEmpty()) return;
            int tSour = 1;
            int tBit = 0;
            for (int x : c) {
                tSour *= sour[x];
                tBit += bit[x];
            }
            ans = Math.min(ans, Math.abs(tSour - tBit));
            return;
        }
        r(i + 1, n, c);
        c.add(i);
        r(i + 1, n, c);
        c.remove(c.size() - 1);
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