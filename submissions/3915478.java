import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt(), k = readInt(), count = 0;
        for (int i = 0; i < n; i ++) {
            String next = next();
            if (i == 0) {
                System.out.print(next);
                count += next.length();
                continue;
            }
            count += next.length();
            if (count > k) {
                System.out.println();
                count = next.length();
                System.out.print(next);
            }
            else {
                System.out.print(" " + next);
            }
        }
        System.out.println();
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