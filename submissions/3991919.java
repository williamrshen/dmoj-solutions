import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        double l = readDouble(), h = readDouble(), w = readDouble();
        double r = readDouble()/2;
        double rv = l * h * w;
        double pv = (r * r * 3.141) * h;
        double ans = rv - pv;
        System.out.printf("%.2f", ans);

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