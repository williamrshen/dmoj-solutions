import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        String[] cow = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
        Arrays.sort(cow);
        int n = readInt();
        String[] a = new String[n];
        String[] b = new String[n];
        for (int i = 0; i < n; i ++) {
            a[i] = next();
            for (int j = 0; j < 5; j ++) {
                b[i] = next();
            }
        }
        do {
            boolean f = true;
            for (int i = 0; i < n; i ++) {
                if (Math.abs(getIndex(a[i], cow) - getIndex(b[i], cow)) != 1) {
                    f = false;
                    break;
                }
            }
            if (f) break;
        } while (np(cow));
        for (String x : cow) System.out.println(x);
    }

    static int getIndex(String x, String[] cow) {
        for (int i = 0; i < cow.length; i ++) {
            if (cow[i].equals(x)) return i;
        }
        return 0;
    }

    static boolean np (String a[]) {
        if (a.length <= 1) return false;
        int p = a.length - 2;
        int q = a.length - 1;
        while (p >= 0 && a[p].compareTo(a[p + 1]) >= 0) p --;
        if (p < 0) return false;
        while (a[q].compareTo(a[p]) <= 0) q--;
        String t = a[p];
        a[p] = a[q];
        a[q] = t;
        for (int l = p + 1, r = a.length - 1; l < r; l ++, r --) {
            t = a[l];
            a[l] = a[r];
            a[r] = t;
        }
        return true;
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