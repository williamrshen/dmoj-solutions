import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        char[] s = readLine().toCharArray();
        int v = 0, h = 0;
        for (char x : s) {
            if (x == 'V') v ++;
            else h ++;
        }
        if (v % 2 == 1) {
            if (h % 2 == 1) {
                System.out.print("4 3\n2 1\n");
            }
            else System.out.print("2 1\n4 3\n");
        }
        else {
            if (h % 2 == 1) {
                System.out.print("3 4\n1 2\n");
            }
            else System.out.print("1 2\n3 4\n");

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