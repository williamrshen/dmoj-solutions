import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int n = readInt(), t = readInt(), m = readInt();
        int[] tt = new int[m], ss = new int[m], dd = new int[m];
        for (int i = 0; i < m; i ++) {
            tt[i] = readInt();
            ss[i] = readInt();
            dd[i] = readInt();
        }
        int floor = 0, time = 0, p = m, ans = 0;
        boolean d = true;
        int[] in = new int[m];
        boolean[] out = new boolean[m];
        Arrays.fill(in, -1);
        while (p > 0) {
            for (int i = 0; i < m; i ++) {
                if (out[i]) continue;
                if (floor == ss[i] && time >= tt[i] && in[i] == -1) {
                    in[i] = time;
                    ans += time - tt[i];
                }
                else if (floor == dd[i] && in[i] != -1) {
                    ans += time - in[i];
                    out[i] = true;
                    p --;
                }
            }
            if (floor == 0) d = true;
            if (floor == n) d = false;
            if (d) floor ++;
            if (!d) floor --;
            time += t;
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