import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    public static class frame implements Comparable<frame> {
        int time;
        int spot;
        public frame (int t, int s) {
            this.time = t;
            this.spot = s;
        }
        @Override
        public int compareTo(frame o) {
            if (this.time > o.time) {
                return 1;
            } else if (this.time < o.time) {
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

        int n = readInt();
        frame[] a = new frame[n];
        for (int i = 0; i < n; i ++) {
            a[i] = new frame(readInt(), readInt());
        }
        Arrays.sort(a);
        double max = -1.0;
        for (int i = 0; i < n-1; i ++) {
            double sdif = Math.abs(a[i].spot - a[i+1].spot);
            double tdif = Math.abs(a[i].time - a[i+1].time);
            double speed = sdif/tdif;
            if (speed > max) max = speed;
        }
        System.out.println(max);
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