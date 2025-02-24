import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(System.in);
        int t = readInt();
        for (int q = 0; q < t; q ++) {
            Stack<Integer> mountain = new Stack<>();
            Stack<Integer> branch = new Stack<>();
            String out = "Y";
            int count = 1;
            int n = readInt();
            for (int i = 0; i < n; i ++) {
                mountain.add(readInt());
            }
            while (true){
                if (mountain.isEmpty()) {
                    if (branch.isEmpty()) {
                        break;
                    }
                    int y = branch.pop();
                    if (y == count) {
                        count ++;
                        continue;
                    } else {
                        out = "N";
                        break;
                    }
                }
                int c = mountain.pop();
                if (c == count) {
                    count ++;
                    continue;
                } else {
                    if (branch.isEmpty()) {
                        branch.add(c);
                        continue;
                    }
                    int x = branch.pop();
                    if (x == count) {
                        count ++;
                        mountain.add(c);
                        continue;
                    } else {
                        if (c > x) {
                            out = "N";
                            break;
                        } else {
                            branch.add(x);
                            branch.add(c);
                            continue;
                        }
                    }
                }
            }
            System.out.println(out);
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
}