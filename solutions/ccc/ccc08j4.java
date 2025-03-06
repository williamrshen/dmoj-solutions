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
        while (true) {
            String line = readLine();
            if (line.equals("0")) break;
            Stack<String> a = new Stack<>();
            for (int i = line.length()-1; i >= 0; i --) {
                char n = line.charAt(i);
                if (n == ' ') continue;
                if (Character.isDigit(n)) {
                    a.add(String.valueOf(n));
                } else {
                    String one = a.pop();
                    String two = a.pop();
                    StringBuilder sb = new StringBuilder();
                    sb.append(one + " ");
                    sb.append(two + " ");
                    sb.append(n);
                    a.add(sb.toString());
                }
            }
            String x = a.pop();
            System.out.println(x);
        }
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
    static char readChar () throws IOException {
        return next().charAt(0);
    }
}