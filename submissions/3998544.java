import java.util.*;
import java.io.*;
public class Homework {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int N = readInt();

        List<Integer>[] tallerList = new List[N+1];
        for (int i = 1; i <= N; i++) {
            tallerList[i] = new ArrayList<>();
        }
        int M = readInt();
        for (int i = 1; i <= M; i++) {
            int t = readInt();
            int s = readInt();
            tallerList[t].add(s);
        }

        int start = readInt();
        int end = readInt();

        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        boolean[] v = new boolean[N+1];
        v[start] = true;
        while(!q.isEmpty()) {
            int curr = q.poll();
            for (int next : tallerList[curr]) {
                if (v[next]) {
                    continue; // skip if visited already
                }
                q.add(next);
                v[next] = true;
            }
            if (v[end]) {
                break;
            }            
        }
        if (v[end]) {
            System.out.println("yes");
            return;
        }
        while (!q.isEmpty()) q.poll();

        q.add(end);
        Arrays.fill(v, false);
        v[end] = true;
        while(!q.isEmpty()) {
            int curr = q.poll();
            for (int next : tallerList[curr]) {
                if (v[next]) {
                    continue; // skip if visited already
                }
                q.add(next);
                v[next] = true;
            }
            if (v[start]) {
                break;
            }
        }
        System.out.println(v[start] ? "no" : "unknown");
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