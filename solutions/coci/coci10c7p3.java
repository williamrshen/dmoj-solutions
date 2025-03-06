import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        int n = readInt(), p = readInt(), ans = 0;
        Stack<Integer>[] gUItARO = new Stack[7];
        for (int i = 1; i < 7; i ++) gUItARO[i] = new Stack<>();
        for (int i = 0; i < n; i ++) {
            int x = readInt(), y = readInt(), z = 0;
            if (gUItARO[x].isEmpty()) { gUItARO[x].add(y); ans ++; }
            else {
                z = gUItARO[x].peek();
                while (z > y) {
                    gUItARO[x].pop();
                    ans ++;
                    if (gUItARO[x].isEmpty()) break;
                    z = gUItARO[x].peek();
                }
                if (z == y) { continue; }
                gUItARO[x].add(y);
                ans ++;
            }
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