import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int n = readInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i ++) {
            s[i] = br.readLine();
        }
        for (int i = 0; i < n - 1; i ++) {
            if (s[i].equals("Bayview")) {
                if (s[i + 1].equals("Bessarion")) {
                    if (s[i + 2].equals("Leslie")) {
                        System.out.println("Y");
                        return;
                    }
                }
            }
            if (s[i].equals("Leslie")) {
                if (s[i + 1].equals("Bessarion")) {
                    if (s[i + 2].equals("Bayview")) {
                        System.out.println("Y");
                        return;
                    }
                }
            }
        }
        System.out.println("N");
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
}