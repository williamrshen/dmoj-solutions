import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        int n = readInt();
        int hp1 = n;
        int hp2 = n;
        int m = readInt();
        for (int i = 1; i <= m; i ++) {
            int one = readInt();
            int two = readInt();
            int three = readInt();
            int four = readInt();
            hp2 -= one * two;
            hp1 -= three * four;

            if (hp2 <= 0 && hp1 <= 0) {
                System.out.println("It's a tie at round " + i + "!");
                return;
            }
            else if (hp2 <= 0 && hp1 > 0) {
                System.out.println("Team 1 wins at round " + i + "!");
                return;
            }
            else if (hp1 <= 0 && hp2 > 0) {
                System.out.println("Team 2 wins at round " + i + "!");
                return;
            }
        }
        System.out.println("Oh no!");

    }




    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}