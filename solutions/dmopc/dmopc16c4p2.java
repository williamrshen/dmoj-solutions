import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int b = readInt();
        int[] start = new int[b];
        int[] end = new int[b];
        int[] point = new int[b];
        int max = 0;
        for (int i = 0; i < b; i ++) {
            start[i] = readInt();
            end[i] = readInt();
            point[i] = readInt();
            max += point[i];

        }
        int f = readInt();

        if (b < 10000) {
            for (int i = 0; i < f; i++) {
                int t = readInt();
                for (int j = 0; j < b; j++) {
                    if (t >= start[j] && t <= end[j]) {
//                    fail[j] = true;
                        max -= point[j];
                        point[j] = 0;
                    }
                }
            }
            System.out.println(max);
        } else {


            int[] fail = new int[f];

            for (int i = 0; i < f; i++) {
                fail[i] = readInt();
            }
            Arrays.sort(fail);
            for (int i = 0; i < b; i++) {
                if (start[i] > fail[f - 1]) continue;
                int find = Arrays.binarySearch(fail, start[i]);
                if (find < 0) {
                    find = -(find + 1);
                    if (fail[find] <= end[i]) {
                        max -= point[i];
                        continue;
                    }
                } else {
                    max -= point[i];
                }
            }

            System.out.println(max);

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