import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException{
        int n = readInt();
        int [] one = new int [n];
        int [] two = new int [n];
        for (int i = 0; i < n; i ++) {
            one[i] = readInt();
        }
        for (int i = 0; i < n; i ++) {
            two[i] = readInt();
        }
        int onet = 0;
        int twot = 0;
        int k = 0;
        for (int i = 0; i < n; i ++) {
            onet += one[i];
            twot += two[i];
            if (onet == twot) k = i+1;
        }
         System.out.println(k);
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