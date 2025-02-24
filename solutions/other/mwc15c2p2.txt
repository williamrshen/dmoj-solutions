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
        int[] t = new int[n];
        Stack<Integer> tt = new Stack<>();
        for (int i = 0; i < n; i ++) t[i] = readInt();
        for (int i = 0; i < n; i ++) {
            while (!tt.empty() && t[tt.peek()] <= t[i]) {
                tt.pop();
            }
            System.out.print((tt.empty()? i : i - tt.peek()) + " ");
            tt.push(i);
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
}