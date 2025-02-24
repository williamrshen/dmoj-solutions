import java.io.*;
import java.util.*;
public class Main {

    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int[] ff = new int[n];
        int[] rf = new int[n];
        int[] df = new int[n];
        for (int i = 0; i < n; i ++) ff[i] = readInt();
        for (int i = 0; i < n; i ++) rf[i] = readInt();
        for (int i = 0; i < n; i ++) df[i] = rf[i] - ff[i];
        int[] m = new int[2000000];
        for (int i = 0; i < n; i ++) {
            m[1000000 + df[i]] ++;
        }
        int max = -1;
        for (int i = 0; i < 2000000; i ++) {
            if (m[i] > max) max = m[i];
        }
        System.out.println(max);

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