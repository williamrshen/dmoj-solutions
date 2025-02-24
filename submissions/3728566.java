import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int n = readInt();
        int q = readInt();
        double[] h = new double[n];
        for (int i = 0; i < n; i ++) {
            long x = readLong();
            long y = readLong();
            h[i] = (x*x)+(y*y);
        }
        Arrays.sort(h);
        for (int i = 0; i < q; i ++) {
            double r = readDouble();
            if (r*r >= h[n-1]) {
                System.out.println(n);
                continue;
            }
            if (h[0] > r*r) {
                System.out.println(0);
                continue;
            }

            int find = Arrays.binarySearch(h, r*r);
            if (find < 0) {
                find = -1*(find+1);
            }
            else {
                int a = find;
                while (true) {
                    if (h[a] > r*r) {
                        find = a;
                        break;
                    }
                    a ++;
                }
            }
            System.out.println(find);
//            int max = n;
//            int min = 0;
//            while (true) {
//                int mid = (max + min)/2;
//                if (h[mid] > r*r && h[mid-1] <= r*r) {
//                    System.out.println(mid);
//                    break;
//                } else {
//                    if (h[mid] > r*r) {
//                        max = mid - 1;
//                    }
//                    if (h[mid] < r*r) {
//                        min = mid + 1;
//                    }
//                }
//            }
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