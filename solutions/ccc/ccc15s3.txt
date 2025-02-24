import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int g = readInt();
        int p = readInt();
        TreeSet<Integer> t = new TreeSet();
        int c = 0;
        for (int i = 1; i <= g; i ++) {
            t.add(i);
        }
        for (int i = 0; i < p; i ++) {
            int gate = readInt();
            if (t.floor(gate) == null) {
                break;
            }
            t.remove(t.floor(gate));
            c ++;
        }
        System.out.println(c);
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