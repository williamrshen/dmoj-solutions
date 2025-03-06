import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int n = readInt();
        LinkedList<Double> streams = new LinkedList<>();
        streams.add(-1.00);
        for (int i = 0; i < n; i ++) {
            streams.add(readDouble());
        }
        while (true) {
            int k = readInt();
            if (k == 77) {
                break;
            } else if (k == 88) {

                int a = readInt();
                double left = streams.get(a);
                double right = streams.get(a+1);
                streams.set(a+1, left+right);
                streams.remove(a);

            } else if (k == 99) {

                int a = readInt();
                int b = readInt();
                double left = streams.get(a) * (b*0.01);
                double right = streams.get(a) - left;
                streams.add(a, left);
                streams.set(a+1, right);

            }
        }
        for (int i = 1; i < streams.size(); i ++) {
            System.out.print(Math.round(streams.get(i)) + " ");
        }
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }

    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble () throws IOException {
        return Double.parseDouble(next());
    }
}