import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int n = readInt();
        String[] a = new String[n];
        String[] b = new String[n];
        int acount = 0;
        int bcount = 0;
        for (int i = 0; i < n; i ++) {
            a[i] = next();
        }
        for (int i = 0; i < n; i ++) {
            b[i] = next();
        }
        for (int i = 0; i < n; i ++) {
            if (a[i].equals("scissors")) {
                if (b[i].equals("paper")) acount ++;
                else if (b[i].equals("rock")) bcount ++;
            } else if (a[i].equals("rock")) {
                if (b[i].equals("scissors")) acount ++;
                else if (b[i].equals("paper")) bcount ++;
            } else {
                if (b[i].equals("rock")) acount ++;
                else if (b[i].equals("scissors")) bcount ++;
            }
        }
        System.out.println(acount + " " + bcount);
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}