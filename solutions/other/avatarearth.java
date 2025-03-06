import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int x = readInt(), y = readInt();
        int[] xx = new int[2], yy = new int[2];
        xx[0] = readInt(); yy[0] = readInt();
        xx[1] = readInt(); yy[1] = readInt();
        Arrays.sort(xx); Arrays.sort(yy);
        if (x > xx[0] && x < xx[1] && y > yy[0] && y < yy[1]) System.out.println("Yes");
        else System.out.println("No");
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