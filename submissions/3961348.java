import java.io.*;
import java.util.*;
public class Main {
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int b = readInt();
        cost[] c = new cost[n];
        int ans = -1;
        for (int i = 0; i < n; i ++) {
            c[i] = new cost(readInt(), readInt());
        }
        for (int i = 0; i < n; i ++) {
//            cost[] temp = Arrays.copyOf(c, c.length);
            cost[] temp = new cost[n];
            for (int j = 0; j < n; j ++) {
                temp[j] = new cost(c[j].price, c[j].ship);
            }
            temp[i].price /= 2;
            Arrays.sort(temp);
            int buy = 0;
            int price = 0;
            while (true) {
                price += temp[buy].price + temp[buy].ship;
                if (price > b) break;
                buy ++;
            }
            if (buy > ans) ans = buy;
        }
        System.out.println(ans);
    }

    public static class cost implements Comparable<cost> {
        int price;
        int ship;
        int total;
        public cost (int p, int s) {
            this.price = p;
            this.ship = s;
            this.total = p + s;
        }
        @Override
        public int compareTo (cost o) {
            return this.total - o.total;
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
}