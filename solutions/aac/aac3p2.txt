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
        int k = readInt();
        int d = readInt();
        int min = 10;
        int[] digits = new int[d];
        for (int i = 0; i < d; i ++) {
            digits[i] = readInt();
        }
        Arrays.sort(digits);
        if (digits[0] == 0 && d == 1) {
            System.out.println(-1);
            return;
        }

        StringBuilder sb = new StringBuilder();
        if (digits[0] == 0 && d > 2) {
            for (int i = 0; i < k; i ++) {
                if (i == 0 || i == k - 1) {
                    sb.append(digits[1]);
                } else sb.append(0);
            }
        } else if (digits[0] == 0 && d <= 2) {
            for (int i = 0; i < k; i ++) sb.append(digits[1]);
        }
        else {
            for (int i = 0; i < k; i ++) sb.append(digits[0]);
        }
        System.out.println(sb);
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