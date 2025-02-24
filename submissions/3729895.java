import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        String[] p = {"A", "B", "C", "D", "E"};
        while (true) {
            int b = readInt();
            int n = readInt();
            if (b == 4) {
                for (int i = 0; i < 5; i ++) {
                    System.out.print(p[i] + " ");
                }
                return;
            }
            if (b == 1) {
                for (int i = 0; i < n; i ++) {
                    String temp = p[0];
                    p[0] = p[1];
                    p[1] = p[2];
                    p[2] = p[3];
                    p[3] = p[4];
                    p[4] = temp;
                }
            }
            if (b == 2) {
                for (int i = 0; i < n; i ++) {
                    String temp = p[4];
                    p[4] = p[3];
                    p[3] = p[2];
                    p[2] = p[1];
                    p[1] = p[0];
                    p[0] = temp;
                }
            }
            if (b == 3) {
                String temp = p[0];
                p[0] = p[1];
                p[1] = temp;
            }

        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
}