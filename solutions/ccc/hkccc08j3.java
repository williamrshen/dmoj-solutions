import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int n = readInt();
        String[] names = new String[n];
        List<Integer> phones = new ArrayList<>();
        int[] calls = new int[n];
        for (int i = 0; i < n; i ++) {
            names[i] = next();
            phones.add(readInt());
            calls[i] = 0;
        }
        int d = readInt();
        for (int i = 0; i < d; i ++) {
            calls[phones.indexOf(readInt())] ++;
        }
        int max = Integer.MIN_VALUE;
        int maxi = 0;
        for (int i = 0; i < n; i ++) {
            if (calls[i] > max) {
                max = calls[i];
                maxi = i;
            } else if (calls[i] == max) {
                if (phones.get(i) < phones.get(maxi)) {
                    max = calls[i];
                    maxi = i;
                }
            }
        }
        System.out.println(names[maxi]);
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