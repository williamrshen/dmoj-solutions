import java.lang.reflect.Array;
import java.util.*;
import java.io.*;
public class TravellingSalesmen {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    static List<Integer> adj[];
    static boolean visited[];
    static int vertices;
    static int depth[];
    static int[] salesmen;
    public static void main(String[] args) throws IOException{
        int nodes = readInt(), connections = readInt(); vertices = nodes+1; depth = new int[nodes+1];
        adj = new ArrayList[nodes];
        for(int i=0;i<nodes;i++) adj[i]=new ArrayList();
        for(int i=0;i<connections;i++){
            int x = readInt()-1, y = readInt()-1;
            adj[x].add(y); adj[y].add(x);
        }
        int k = readInt();
        salesmen = new int[k];
        for(int i=0;i<k;i++){
            salesmen[i]=readInt()-1;
        }
        BFS(1);
        int ans = -1;
        for(int i=0;i<depth.length;i++){
            ans = Math.max(ans, depth[i]);
        }
        System.out.println(ans);
    }
    static void BFS(int st){
        Queue<Integer> q = new LinkedList();
        boolean vis[] = new boolean[vertices];
        for(int i=0;i< salesmen.length;i++){
            q.add(salesmen[i]);
            depth[i] = 0;
            vis[salesmen[i]]=true;
        }
        while(!q.isEmpty()) {
            int cur = q.poll();
            for(int nxt : adj[cur]) {
                if(!vis[nxt]) {
                    q.add(nxt); vis[nxt]=true;
                    depth[nxt]=depth[cur]+1;
                }
            }
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