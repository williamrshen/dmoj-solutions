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

        int n = readInt(); List<String> a = new ArrayList<>();
        for (int i = 0; i < n; i ++) a.add(next());
        Collections.sort(a, new c());
        for (String x : a) System.out.print(x);
    }

    static class c implements Comparator <String> {
        public int compare(String x, String y) {
            return (y+x).compareTo(x + y);
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
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
}