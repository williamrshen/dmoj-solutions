import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int n = readInt(), ans = 0;
        int a = readInt(), b = readInt(), c = readInt();
        while (n > 0) {
            n --;
            a ++;
            if (n >= 0) ans ++;
            if (a % 35 == 0) n += 30;
            
            n --;
            b ++;
            if (n >= 0) ans ++;
            if (n >= 0 && b % 100 == 0) n += 60;
            
            n --;
            c ++;
            if (n >= 0) ans ++;
            if (n >= 0 && c % 10 == 0) n += 9;
        }
        System.out.println("Martha plays " + ans + " times before going broke.");
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