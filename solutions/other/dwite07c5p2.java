import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        for (int h = 0; h < 5; h ++) {
            int n = readInt();
            int[] prime = {2,3,5,7,11,13,17,19,23,29};
            int i = 0;
            int count = 0;
            while (i < 10) {
                if (n%prime[i] != 0) {
                    i ++;
                    continue;
                }
                n = n/prime[i];
                count ++;
            }
            if (count == 1) count = 0;
            System.out.println(count);
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