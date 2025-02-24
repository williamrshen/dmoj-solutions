import java.lang.reflect.Array;
import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        String password = next();
        char[] p = password.toCharArray();
        int lcount = 0;
        int ucount = 0;
        int ncount = 0;
        int count = 0;
        for (char x : p) {
            if (Character.isAlphabetic(x)) {
                count ++;
                if (Character.isLowerCase(x)) lcount ++;
                else ucount ++;
            } else if (Character.isDigit(x)) {
                count ++;
                ncount ++;
            } else {
                System.out.print("Invalid");
                return;
            }
        }
        if (count > 12 || count < 8 || lcount < 3 || ucount < 2 || ncount < 1) System.out.print("Invalid");
        else System.out.print("Valid");

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