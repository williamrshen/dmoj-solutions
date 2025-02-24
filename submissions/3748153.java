import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static class v implements Comparable<v> {
        public String name;
        public int skill;
        public int order;
        public v (String n, int s, int o) {
            this.name = n;
            this.skill = s;
            this.order = o;
        }
        @Override
        public int compareTo(v o) {
            if (this.skill > o.skill) {
                return 1;
            } else if (this.skill < o.skill) {
                return -1;
            } else {
                return this.order - o.order;
            }
        }
    }
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        v[] e = new v[n];
        for (int i = 0; i < n; i ++) {
            e[i] = new v(sc.next(), sc.nextInt(), i);
        }
        Arrays.sort(e);

        int q = sc.nextInt();
        for (int i = 0; i < q; i ++) {
            int s = sc.nextInt();
            int a = sc.nextInt();
            boolean f = false;
            for (int j = 0; j < n; j ++) {
                if (e[j].skill <= s + a && e[j].skill >= s) {
                    System.out.println(e[j].name);
                    f = true;
                    break;
                }
            }
            if (!f) {
                System.out.println("No suitable teacher!");
            }
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