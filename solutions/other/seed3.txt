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
        int eye = readInt();
        int n = readInt();
        int j = readInt();
        int ans = 0;
        int[] dif = new int[eye + 2];
        for (int i = 0; i < j; i ++) {
            int x = readInt();
            int y = readInt();
            int z = readInt();
            dif[x] += z;
            dif[y + 1] -= z;
        }
        for (int i = 1; i <= eye; i ++) {
            dif[i] += dif[i - 1];
            if (dif[i] < n) ans ++;
        }
        System.out.println(ans);
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