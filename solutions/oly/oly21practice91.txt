import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static long[] p = new long[10000009];
    public static void main(String[] args) throws IOException {

        char[] s = readLine().toCharArray();
        int u = 0;
        int l = 0;
        for (char x : s) {
            if (x >= 'A' && x <= 'Z') u ++;
            if (x >= 'a' && x <= 'z') l ++;
        }
//        System.out.println(u + " " + l);
        if (u == l) System.out.println("YES");
        else System.out.println("NO");
    }




    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long rl () throws IOException {
        return Long.parseLong(next());
    }
    static int ri () throws IOException {
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