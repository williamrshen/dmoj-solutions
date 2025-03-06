import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int t = readInt();
        for (int i = 0; i < t; i ++) {
            int n = readInt();
            int k = readInt();
            int c = 0;
            int a = 0;
            for (int j = 0; j < n; j ++) {
                a += readInt();
                if (a >= k) {
                    c ++;
                    a = 0;
                }
            }
            System.out.println(c);
        }
    }





    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}