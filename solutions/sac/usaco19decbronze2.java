import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int n = readInt();
        String s = br.readLine();
        for (int i = 1; i <= n; i ++) {
            boolean x = true;
            Set<String> a = new HashSet<>();
            for (int j = 0; j + i <= n; j ++) {
                String ss = s.substring(j, j + i);
                if (a.contains(ss)) {
                    x = false;
                    break;
                }
                a.add(ss);
            }
            if (x) {
                System.out.println(i);
                return;
            }
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