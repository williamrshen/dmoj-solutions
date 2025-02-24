import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int c = 0;
        boolean[] con = new boolean[4];
        Arrays.fill(con, false);
        int[][] grid = new int[4][4];
        for (int i = 0; i < 4 ; i ++) {
            for (int j = 0; j < 4; j ++) {
                grid[i][j] = readInt();
                con[i] = con[j] = true;
                if (grid[i][j] == 1) c ++;
            }
        }
        for (int i = 0; i < 4; i ++) {
            boolean connected = false;
            for (int j = 0; j < 4; j ++) {
                if (grid[i][j] == 1) connected = true;
            }
            if (!connected) {
                System.out.println("No");
                return;
            }
        }
        for (int i = 0; i < 4; i ++) {
            boolean connected = false;
            for (int j = 0; j < 4; j ++) {
                if (grid[j][i] == 1) connected = true;
            }
            if (!connected) {
                System.out.println("No");
                return;
            }
        }
        if (c != 6) {
            System.out.println("No");
        }
        else System.out.println("Yes");
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