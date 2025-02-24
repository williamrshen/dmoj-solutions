import java.util.*;
import java.io.*;
public class Main {
  static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int n = readInt(), m = readInt(), in[] = new int[n + 1];
        List<Integer>[] ok = new List[n + 1];
        for (int i = 1; i <= n; i ++) ok[i] = new ArrayList<>();
        for (int i = 0; i < m; i ++) {
            int x = readInt(), y = readInt();
            ok[x].add(y); in[y] ++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i ++) {
            if (in[i] == 0) q.add(i);
        }
        while (!q.isEmpty()) {
            int c = q.poll();
            for (int x : ok[c]) {
                in[x] --;
                if (in[x] == 0) q.add(x);
            }
        }
        boolean ans = true;
        for (int i = 1; i <= n; i ++) {
          if (in[i] > 0) { ans = false; break; }
        }
        System.out.println(ans ? "Y" : "N");
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