import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int r = readInt();
        int c = readInt();
        boolean[] col = new boolean[c];
        boolean[] row = new boolean[r];
        for (int i = 0; i < r; i ++) {
            char[] a = readLine().toCharArray();
            for (int h = 0; h < a.length; h ++) {
                if (a[h] == 'X') {
                    col[h] = true;
                    row[i] = true;
                }
            }
        }
        int q = readInt();
        for (int i = 0; i < q; i ++) {
            int x = readInt()-1;
            int y = readInt()-1;
            if (col[x] || row[y]) System.out.println("Y");
            else System.out.println("N");
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