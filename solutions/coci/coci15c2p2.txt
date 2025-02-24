import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int n;
    static int m;
    static boolean[][] c;
    static int count;
    public static void main(String[] args) throws IOException {

        n = readInt();
        m = readInt();
        c = new boolean[n + 1][n + 1];
        for (int i = 1; i <= m; i ++) {
            int x = readInt();
            int y = readInt();
            c[x][y] = c[y][x] = true;
        }
        List<Integer> cb = new ArrayList<>();
        getCombination(1, n, cb);
        System.out.println(count);
    }
    static void getCombination(int i, int n, List<Integer> comb) {
        if(i > n) {
            count ++;
            return;
        }
        getCombination(i+1, n, comb);
        boolean can = true;
        for (int x : comb) {
            if (c[x][i]) can = false;
        }
        if (can) {
            comb.add(i);
            getCombination(i + 1, n, comb);
            comb.remove(comb.size() - 1);
        }
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