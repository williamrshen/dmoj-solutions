import java.io.*;
import java.util.*;

public class Main {
    static int N, M, p, q;
    static ArrayList<Integer>[] adj;
    
    static BufferedReader br;
    static StringTokenizer st;
    
    public static String solve() {
        
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        boolean[] vis = new boolean[N + 5];
        Arrays.fill(vis, false);
        // Traverse from p to q
        queue.addLast(p); vis[p] = true;
        while (!queue.isEmpty()) {
            
            int removed = queue.removeLast();
            for (int person : adj[removed - 1]) {
                
                if (person == q) {
                    return "yes";
                }
                if (vis[person]) continue;
                
                queue.addLast(person);
                vis[person] = true;
                
            }
            
        }
        
        // Traverse from q to p
        Arrays.fill(vis, false);
        queue.add(q); vis[q] = true;
        while (!queue.isEmpty()) {
            
            int removed = queue.removeLast();
            for (int person : adj[removed - 1]) {
                
                if (person == p) {
                    return "no";
                }
                if (vis[person]) continue;
                
                queue.addLast(person);
                vis[person] = true;
                
            }
            
        }
        
        return "unknown";
        
    }
    
    public static void main(String[] args) throws IOException
    {
        
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        adj = new ArrayList[N];
        
        for (int i = 0; i < adj.length; i++) {
            adj[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < M; i++) {
            
            st = new StringTokenizer(br.readLine());
            int p1 = Integer.parseInt(st.nextToken());
            int p2 = Integer.parseInt(st.nextToken());
            adj[p1 - 1].add(p2);
            
        }
        
        st = new StringTokenizer(br.readLine());
        p = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());
        
        System.out.println(solve());
        
    }
}