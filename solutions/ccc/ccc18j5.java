import java.util.*;
import java.io.*;
public class Test {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt(), cnt = 0;
		ArrayList<Integer> [] adj = new ArrayList[n+1];
		for(int i = 1; i <= n; i ++) adj[i] = new ArrayList<Integer>();
		for(int i = 1; i <= n; i ++){
			int m = readInt();
			for(int j = 1; j <= m; j ++){
				int x = readInt();
				adj[i].add(x);
			}
		}
		Queue<Integer> q = new LinkedList<>();
		boolean[] vis = new boolean[n + 1];
		int[] dis = new int[n + 1];
		q.add(1);
		vis[1] = true;
		dis[1] = 0;
		while(!q.isEmpty()){
			int cur = q.poll();
			cnt ++;
			for(int v: adj[cur]) {
				if(!vis[v]){
					q.add(v);
					vis[v]=true;
					dis[v]=dis[cur] + 1;
				}
			}
		}
		System.out.println(cnt == n ? "Y": "N");
		int ans = Integer.MAX_VALUE;
		for(int i = 1; i <= n; i ++)
			if(adj[i].isEmpty() && vis[i]) ans = Math.min(ans, dis[i]+1);
		System.out.println(ans);
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
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
}