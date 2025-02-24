import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static int adj[][];
    public static void main(String[] args) throws IOException{
        int [] x = {1, 2, 6, 3, 4, 5, 3, 4, 7, 3, 3, 8, 9, 9, 15, 12, 12, 11, 13, 16, 16, 18};
        int [] y = {6, 6, 7, 6, 6, 6, 4, 5, 8, 5, 15, 9, 10, 12, 13, 13, 11, 10, 14, 18, 17, 17};
        adj = new int[50][50];
        for(int i = 0; i < x.length; i ++) adj[x[i]][y[i]] = adj[y[i]][x[i]] = 1;
        char o = readCharacter();
        while(o != 'q') {
            if(o == 'i') {
                int u = readInt();
                int v = readInt();
                adj[u][v] = adj[v][u] = 1;
            }
            else if(o == 'd') {
                int u = readInt(), v = readInt();
                adj[u][v] = adj[v][u] = 0;
            }
            else if(o == 'n') {
                int u = readInt();
                int sum = 0;
                for(int i = 0; i < adj[u].length; i ++) sum += adj[u][i];
                System.out.println(sum);
            }
            else if(o == 'f') {
                int u = readInt();
                int dis[] = new int[50];
                int count = 0;
                boolean vis[] = new boolean[50];
                BFS(u, dis, vis);
                for(int i = 0; i < dis.length; i ++)
                    if(dis[i] == 2) count++;
                System.out.println(count);
            }
            else if (o == 's'){
                int u = readInt();
                int v = readInt();
                int dis[] = new int[50];
                boolean vis[] = new boolean[50];
                BFS(u, dis, vis);
                System.out.println(vis[v] ? dis[v] : "Not connected");
            }
            o = readCharacter();
        }
    }
    static void BFS(int start, int dis[], boolean vis[]) {
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        vis[start] = true;
        dis[start] = 0;
        while(!q.isEmpty()) {
            int cur = q.poll();
            for(int next = 0; next < adj[cur].length; next++) {
                if(adj[cur][next] == 1 && !vis[next]) {
                    q.add(next); vis[next]=true;
                    dis[next] = dis[cur] + 1;
                }
            }
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
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}