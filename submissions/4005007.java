import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int n = readInt();
        Map<Long, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i ++) {
            long s = readLong();
            Integer a = map.get(s);
            if (a == null) {
                a = 0;
            }
            map.put(s, a + 1);
        }
        List<Integer> c = map.values().stream().sorted().collect(Collectors.toList());
        if (c.size() == 1) {
            System.out.println(n);
        }
        else {
            System.out.println((c.get(c.size() - 2)) + (c.get(c.size() - 1)));
        }


    }
    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}