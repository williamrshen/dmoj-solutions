import java.io.*;
import java.util.*;
public class Main {

    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int m = readInt();
        Queue<Integer> q = new LinkedList<>();
        boolean[] v = new boolean[(int)1e7 + 100];
        int[] d = new int[(int)1e7 + 100];
        q.add(n);
        v[n] = true;
        d[n] = 0;
        while (!q.isEmpty()) {
            int c = q.poll();
//            go to n - 1 square
            if (c - 1 > 0) {
                if (!v[c - 1]) {
                    q.add(c - 1);
                    v[c - 1] = true;
                    d[c - 1] = d[c] + 1;
                }
            }
//            go to n - 3 square
            if (c - 3 > 0) {
                if (!v[c - 3]) {
                    q.add(c - 3);
                    v[c - 3] = true;
                    d[c - 3] = d[c] + 1;
                }
            }
//            go to n/2 square
            if (c % 2 == 0) {
                if (!v[c / 2]) {
                    q.add(c / 2);
                    v[c / 2] = true;
                    d[c / 2] = d[c] + 1;
                }
            }
//            go to 3n square
            if (3 * c <= (int)10e6) {
                if (!v[3 * c]) {
                    q.add(c * 3);
                    v[c * 3] = true;
                    d[c * 3] = d[c] + 1;
                }
            }
        }

        System.out.println(d[m]);
    }



    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}