import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {

        Map<String, Integer> mm = new HashMap<>();
        Map<Integer, String> mmm = new HashMap<>();
        int m = readInt();
        int[] in = new int[m * 2 + 2];
        List<Integer>[] adj = new List[m * 2 + 2];
        for (int i = 1; i < m * 2 + 2; i ++) adj[i] = new ArrayList<>();
        int ok = 1;
        for (int i = 0; i < m; i ++) {
            String a = next(), b = next();
            if (!mm.keySet().contains(a)) {
                mm.put(a, ok); mmm.put(ok, a); ok ++;
            }
            if (!mm.keySet().contains(b)) {
                mm.put(b, ok); mmm.put(ok, b); ok ++;
            }
            adj[mm.get(b)].add(mm.get(a));
            in[mm.get(a)] ++;
        }
        ArrayList<String> ans = new ArrayList<>();
        while (true) {
          int c = -1;
          for (int i = 1; i < ok; i ++) {
              if (in[i] == 0) {
                in[i] --;
                c = i;
                break;
              }
          }
          if (c == -1) break;
          System.out.println(mmm.get(c));
          for (int x : adj[c]) {
            in[x] --;
          }
        }

        // for (int i = ans.size() - 1; i >= 0; i --) System.out.println(ans.get(i));

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