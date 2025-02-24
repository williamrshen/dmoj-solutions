import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i ++) a[i] = readLong();

        long dTurn = 0;
        long aTurn = 0;
        for (long x : a) {
            if (x%2 == 0) {
                dTurn += x/2;
            }
            else {
                aTurn += (x+1)/2;
            }
        }
        if (dTurn > aTurn) System.out.println("Duke");
        else System.out.println("Alice");
    }


    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}