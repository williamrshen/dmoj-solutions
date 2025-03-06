import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int[] d = new int[6];
        d[3] = 1;
        for (int i = 0; i < n; i ++) {
            int one = readInt();
            int two = readInt();
            int temp = d[one];
            d[one] = d[two];
            d[two] = temp;
        }
        for (int i = 1; i <= 5; i ++) {
            if (d[i] == 1) System.out.println(i);
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}