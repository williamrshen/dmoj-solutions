import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int a = readInt(), aa = readInt();
        int b = readInt(), bb = readInt();
        int c = readInt(), cc = readInt();
        double d = readDouble();

        double d1 = Math.sqrt(Math.pow(a - c, 2) + Math.pow(aa - cc, 2));
        double d2 = Math.sqrt(Math.pow(b - c, 2) + Math.pow(bb - cc, 2));
        if (d1 <= d || d2 <= d) System.out.println("Yes");
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