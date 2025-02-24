import java.util.*;
import java.io.*;
public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{

        String[] s = new String[1000];
        String[] h = new String[1000];
        String t;
        int l = readInt();
        for (int z = 0; z < l; z ++) {
            int n = readInt();
            int p = 0;
            for (int i = 0; i < n; i ++) h[p ++] = readLine();
            int max = 0;
            s[0] = h[p - 1];
            p = 0;
            for (int i = 0; i < n; i ++) {
                int a = 0;
                while (a <= p && !h[i].equals(s[a])) a ++;
                s[a] = h[i];
                p = a;
                if (p >= max) max = p;
            }
            System.out.println(n * 10 - 20 * max);
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