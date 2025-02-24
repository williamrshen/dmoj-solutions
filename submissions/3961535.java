import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int g = readInt(), p = readInt();
        TreeSet<Integer> t = new TreeSet<>();
        int ans = 0;
        for (int i = 1; i <= g; i ++) t.add(i);
        for (int i = 0; i < p; i ++) {
            Integer x = t.floor(readInt());
            if (x == null) break;
            t.remove(x);
            ans ++;
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