import java.util.*;
import java.io.*;
public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{

        int m = readInt(), n = readInt();
        boolean[][] map = new boolean[26][26];
        for (int i = 0; i < m; i ++) {
            String a = next(), b = next();
            map[a.charAt(0) - 'A'][b.charAt(0) - 'A'] = map[b.charAt(0) - 'A'][a.charAt(0) - 'A'] = true;
        }
        for (int k = 0; k < n; k ++) {
            String st = next(), ed = next();
            Queue<Integer> q = new LinkedList<>();
            boolean[] v = new boolean[26];
            int[] p = new int[26];
            q.add(st.charAt(0) - 'A');
            p[st.charAt(0) - 'A'] = 0;
            v[st.charAt(0) - 'A'] = true;
            while (!q.isEmpty()) {
                int c = q.poll();
                for (int i = 0; i < 26; i ++) {
                    if (map[c][i] && !v[i]) {
                        q.add(i);
                        v[i] = true;
                        p[i] = c;
                    }
                }
            }
            ArrayList<Character> ans = new ArrayList<>();
            char cur = ed.charAt(0);
            ans.add(cur);
            while (true) {
                ans.add((char)(p[cur - 'A'] + 'A'));
                if (cur == st.charAt(0)) break;
                cur = (char)(p[cur - 'A'] + 'A');
            }
            for (int i = ans.size() - 2; i >= 0; i --) {
                System.out.print(ans.get(i));
            }
            System.out.println();
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