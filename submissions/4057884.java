import java.util.*;
import java.io.*;
public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static class row {
        ArrayList<Integer> rows = new ArrayList();
        int c;
        row(ArrayList<Integer> l) {
            this.rows = l; this.c = find(c);
        } 
        public int find(int c) {
            return rows.get(c);
        }
    }
    static class specialcmp implements Comparator<row> {
        int c;
        public specialcmp (int cc) {
          c = cc;
        }
        public int compare(row a, row b) {
            // if(a.rows.get(c) < .rows.get(c)) return 1;
            // return 0;
            return Integer.compare(a.rows.get(c), b.rows.get(c));
        }
    }
    public static void main(String[] args) throws IOException{
        int r = readInt(), c = readInt();
        row[] a = new row[r];
        for(int i = 0; i < r; i++) {
            ArrayList<Integer> t = new ArrayList();
            for(int j = 0; j < c; j++) {
                t.add(readInt());
            }
            a[i] = new row(t);
        }
        int n = readInt();
        for(int i = 0; i < n; i++) {
            Arrays.sort(a, new specialcmp(readInt() - 1));
        }
        // Arrays.sort(a, new specialcmp());
        for(int i = 0; i < r; i++) {
            for (int x : a[i].rows) System.out.print(x + " ");
            System.out.println();
        }
        
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