import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;


public class Main {
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int t = readInt();
        int n = readInt();
        List<Integer> s = new ArrayList<>();
        for (int i = 0; i < n; i ++) {
            s.add(readInt());
        }
        Collections.sort(s, new Sort());
        int count = 0;
        int c = 0;
        for (int i = 0; i < s.size(); i ++) {
            if (Math.abs(s.get(i) - c) <= t) {
                t -= Math.abs(s.get(i) - c);
                c = s.get(i);
                count ++;
            } else {
                break;
            }
        }
        System.out.println(count);
    }

    public static class Sort implements Comparator<Integer> {
        public int compare(Integer a, Integer b) {
            return Integer.compare(Math.abs(a), Math.abs(b));
        }
    }


    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
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