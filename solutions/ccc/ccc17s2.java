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
        int n = readInt();
        int[] t = new int[n];
        for (int i = 0; i < n; i ++) {
            t[i] = readInt();
        }
        Arrays.sort(t);
        if (n%2 == 0) {
            for (int i = 0; i < n/2; i ++) {
                System.out.print(t[(n/2) - 1 - i] + " ");
                System.out.print(t[i + n/2] + " ");
            }
        } else if (n%2 == 1) {
            for (int i = 0; i < (n/2); i ++) {
                System.out.print(t[n/2 - i] + " ");
                System.out.print(t[(n/2) + 1 + i] + " ");
            }
            System.out.println(t[0]);
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
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}