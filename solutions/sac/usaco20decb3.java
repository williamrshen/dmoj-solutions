import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        char[] dir = new char[n + 1];
        int[] x = new int[n + 1];
        int[] y = new int[n + 1];
        List<Intersection> list = new ArrayList<>();
        for (int i = 1; i <= n; i ++) {
            dir[i] = readCharacter();
            x[i] = readInt();
            y[i] = readInt();
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                if (dir[i] == dir[j]) continue;
                int ex = x[i];
                int ey = y[i];
                int nx = x[i];
                int ny = y[i];
                if (dir[i] == 'E') {
                    nx = x[j];
                    ny = y[j];
                }
                else {
                    ex = x[j];
                    ey = y[j];
                }
                if (ex < nx && ny < ey) {
                    list.add(new Intersection(nx, ey, i, j));
                }
            }
        }
        Collections.sort(list);
        boolean[] stop = new boolean[n + 1];
        int[] ans = new int[n + 1];
        for (Intersection a : list) {
            if (stop[a.cow1] || stop[a.cow2]) continue;
            int timea = a.x - x[a.cow1] + a.y - y[a.cow1];
            int timeb = a.x - x[a.cow2] + a.y - y[a.cow2];
            if (timea < timeb) {
                stop[a.cow2] = true;
                ans[a.cow2] = timeb;
            }
            else if (timeb < timea) {
                stop[a.cow1] = true;
                ans[a.cow1] = timea;
            }
        }
        for (int i = 1; i <= n; i ++) {
            System.out.println(stop[i] ? ans[i] : "Infinity");
        }
    }

    static class Intersection implements Comparable<Intersection> {
        int x;
        int y;
        int cow1;
        int cow2;
        public Intersection (int x, int y, int c1, int c2) {
            this.x = x;
            this.y = y;
            this.cow1 = c1;
            this.cow2 = c2;
        }
        public int compareTo (Intersection o) {
            if (x != o.x) return Integer.compare(x, o.x);
            return Integer.compare(y, o.y);
        }
    }

    static class Cow {
        char direction;
        long x;
        long y;
        public Cow (char d, int x, int y) {
            this.direction = d;
            this.x = x;
            this.y = y;
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
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}