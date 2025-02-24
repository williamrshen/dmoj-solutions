import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int r = readInt();
        int c = readInt();
        Row[] s = new Row[r];
        for (int i = 0; i < r; i ++) {
            int[] row = new int[c];
            for (int j = 0; j < c; j ++) {
                row[j] = readInt();
            }
            s[i] = new Row(row);
        }

        int n = readInt();
        for (int i = 0; i < n; i ++) {
            int whichCol = readInt();
            C aaa = new C(whichCol);
            Arrays.sort(s, aaa);
        }

        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j ++) {
                System.out.print(s[i].row[j] + " ");
            }
            System.out.println();
        }
    }

    static class C implements Comparator<Row> {
        int wc;
        public C (int w) {
            this.wc = w - 1;
        }
        public int compare (Row x, Row y) {
            return Integer.compare(x.row[wc], y.row[wc]);
        }
    }

    public static class Row {
        int[] row;
        public Row (int[] r) {
            this.row = r;
        }
    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static long readLong () throws IOException {
        return Long.parseLong(next());
    }
}