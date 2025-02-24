import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int[] a = new int[6];

        for (int i = 0; i < n; i ++) {
            String color = next();
            if (color.equals("red")) a[0] ++;
            if (color.equals("orange")) a[1] ++;
            if (color.equals("yellow")) a[2] ++;
            if (color.equals("green")) a[3] ++;
            if (color.equals("blue")) a[4] ++;
            if (color.equals("black")) a[5] ++;
        }
        int max = -1;
        for (int i = 0; i < 6; i ++) {
            if (a[i] > max) max = a[i];
        }
        int ans = Math.min(max, n - max + 1) + (n - max);
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}