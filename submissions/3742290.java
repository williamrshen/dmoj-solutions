import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int t = readInt();
        for (int q = 0; q < t; q ++) {
            String out = "Y";
            int n = readInt();
            int small = n + 1;
            Set<Integer> s = new HashSet<>();
            for (int j = 0; j < n; j ++) {
                int c = readInt();
                if (c < small) {
                    s.add(c+1);
                    small = c;
                } else if (s.contains(c)) {
                    s.remove(c);
                    s.add(c+1);
                } else {
                    out = "N";
                }
            }
            System.out.println(out);
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
}