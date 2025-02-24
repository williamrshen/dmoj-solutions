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
        int t = 0;
        int s = 0;
        for (int i = 0; i < n; i ++) {
            char[] line = readLine().toLowerCase().toCharArray();
            for (int j = 0; j < line.length; j ++) {
                if (line[j] == 't') {
                    t ++;
                } else if (line[j] == 's') {
                    s ++;
                }
            }
        }
        if (t > s) System.out.println("English");
        else System.out.println("French");
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