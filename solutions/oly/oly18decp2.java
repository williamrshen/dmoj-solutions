import java.util.*;
import java.io.*;
import java.util.stream.Collectors;

public class Main {

    static int[] par;
    static int[] sz;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int h = readInt(), w = readInt();
        int[][] m = new int[h][w];
        for (int i = 0; i < h; i ++) {
            for (int j = 0; j < w; j ++) {
                m[i][j] = readInt();
            }
        }
        for (int i = w - 1; i >= 0; i --) {
            for (int j = 0; j < h - 1; j ++) {
                System.out.print(m[j][i] + " ");
            }
            System.out.println(m[h - 1][i]);
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