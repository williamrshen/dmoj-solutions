import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        for (int k = 0; k < 10; k ++) {
            int n = readInt();
            ArrayList<Integer> train = new ArrayList<>();
            int cost = 0;
            for (int i = 0; i < n; i ++) {
                train.add(readInt());
            }
            for (int i = n-1; i > 0; i --) {
                int a = train.indexOf(i);
                int b = train.indexOf(i + 1);
                if (a > b) {
                    train.remove(a);
                    train.add(0, i);
                    cost += a;
                }
            }
            System.out.println(cost);
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