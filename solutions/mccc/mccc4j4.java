import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static class pair implements Comparable<pair> {
        public int c;
        public int p;
        public pair(int c, int p) {
            this.c = c;
            this.p = p;
        }
        public int compareTo(pair comp) {
            if(p == comp.p) return c - comp.c;
            else return comp.p - p;
        }
    }
    public static void main(String[] args) throws IOException {
        int n = readInt(), s = readInt();
        pair[][] country = new pair[n/s][n];
        for(int i = 0; i < n/s; i++) {
            for(int j = 0; j < s; j++) {
                int temp = readInt();
                country[i][temp - 1] = new pair(temp, 0);
            }
        }
        for(int i = 0; i < n/s; i++) {
            for(int j = 0; j < n; j++) {
                if(country[i][j] == null) country[i][j] = new pair(10000, 0);
            }
        }
        for(int i = 0; i < (s-1)*n/2; i++) {
            int a = readInt(), b = readInt(), index = -1;;
            for(int j = 0; j < n/s; j++) {
                if(country[j][a - 1] != null && country[j][a - 1].c == a) {
                    index = j;
                    break;
                }
            }
            char c = readChar();
            if(c == 'W') country[index][a - 1].p += 3;
            else if(c == 'L') country[index][b - 1].p += 3;
            else {
                country[index][a - 1].p += 1;
                country[index][b - 1].p += 1;
            }
        }
        for(int i = 0; i < n/s; i++) {
            Arrays.sort(country[i]);
        }

        int k = readInt() - 1;
        System.out.print(country[0][k].c);
        for(int i = 1; i < n/s; i++) {
            System.out.print(" " + country[i][k].c);
        }
        System.out.println();
    }
    static String next () throws IOException{
        while(st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException{
        return Integer.parseInt(next());
    }
    static char readChar () throws IOException{
        return next().charAt(0);
    }
    static String readLine () throws IOException{
        return br.readLine();
    }
}