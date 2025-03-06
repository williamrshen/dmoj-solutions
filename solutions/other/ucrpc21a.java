import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int m = readInt();
        int ans = 0;
        char[][] ss = new char[n][m];
        for (int i = 0; i < n; i ++) {
            ss[i] = br.readLine().toCharArray();
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if (ss[i][j] == 't') {
                    ans ++;
                }
            }
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}