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
        for (int i = 0; i < n; i ++) {
            if (readLong()*readLong() != readLong()) {
                System.out.println("16 BIT S/W ONLY");
            } else {
                System.out.println("POSSIBLE DOUBLE SIGMA");
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

    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
}