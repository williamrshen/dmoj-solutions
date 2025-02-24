import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int n = readInt();
        Map<String, String> own = new HashMap<>();
        for (int i = 0; i < n; i ++) {
            String a = next();
            String b = next();
            own.put(b, a);
        }
        int d = readInt();
        Map<String, Integer> freq = new TreeMap<>();
        for (int i = 0; i < d; i ++) {
            String p = next();
            freq.put(p, freq.getOrDefault(p, 0) + 1);
        }
        int max = 0; String phone = "";
        for (String k : freq.keySet()) {
            if (freq.get(k) > max) {
                max = freq.get(k);
                phone = k;
            }
        }
        System.out.println(own.get(phone));
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}