import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        char[] a = next().toCharArray();
        char[] h = next().toCharArray();
        int i = 0;
        int check = 0;
        int count = 0;
        while (true) {
            if (a[i] == h[check]) {
                check ++;
            }
            if (check == h.length) break;
            i ++;
            if (i == 26) {
                i = 0;
                count ++;
            }
        }
        System.out.println(count + 1);
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