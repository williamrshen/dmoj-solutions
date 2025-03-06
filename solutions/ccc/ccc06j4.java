import java.util.*;
import java.io.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int[] in = new int[30];
        List<Integer>[] ok = new List[30];
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < 30; i ++) ok[i] = new ArrayList<>();
        ok[1].add(7); in[7] ++;
        ok[1].add(4); in[4] ++;
        ok[2].add(1); in[1] ++;
        ok[3].add(4); in[4] ++;
        ok[3].add(5); in[5] ++;
        int a = readInt(), b = readInt();
        while (a != 0) {
            ok[a].add(b); in[b] ++;
            a = readInt(); b = readInt();
        }
        for (int i = 1; i <= 7; i ++) Collections.sort(ok[i]);
        PriorityQueue<Integer> q = new PriorityQueue<>();
        boolean[] v = new boolean[30];
        for (int i = 1; i <= 7; i ++) {
            if (in[i] == 0 && !v[i]) { q.add(i); v[i] = true; break; }
        }
        while (!q.isEmpty()) {
            int c = q.poll();
            ans.add(c);
            for (int x : ok[c]) {
                in[x] --;
            }
            for (int i = 1; i <= 7; i ++) {
                if (in[i] == 0 && !v[i]) { q.add(i); v[i] = true; }
            }
        }
        boolean flag = false;
        for (int i = 1; i <= 7; i ++) {
            if (!v[i]) { flag = true; break; }
        }
        if (flag) System.out.println("Cannot complete these tasks. Going to bed.");
        else {
            for (int i = 0; i < ans.size() - 1; i ++) {
                System.out.print(ans.get(i) + " ");
            }
            System.out.println(ans.get(ans.size() - 1));
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