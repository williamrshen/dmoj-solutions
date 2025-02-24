import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {

    public static class profile implements Comparable<profile> {
        String name;
        int time;
        public profile (String n, int t) {
            this.name = n;
            this.time = t;
        }
        @Override
        public int compareTo (profile o){
            if (this.time < o.time) {
                return 1;
            } else if (this.time > o.time) {
                return -1;
            } else {
                return 0;
            }
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int n = readInt(), p = readInt();
        profile[] a = new profile[n];
        for (int i = 0; i < n; i ++) {
            a[i] = new profile("",0);
        }
        for (int i = 0; i < n; i ++) {
            a[i].name = next();
        }
        for (int i = 0; i < p; i ++) {
            for (int j = 0; j < n; j ++) {
                a[j].time += readInt();
            }
        }
        Arrays.sort(a);
        for (int i = 0; i < n; i ++) {
            System.out.println(i+3 + ". " + a[i].name);
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
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}