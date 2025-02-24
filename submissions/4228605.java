import java.util.*;

class edges implements Comparable<edges> {
    int to;
    Integer cost;
    
    public edges(int t, int c) {
        to = t;
        cost = c;
    }

    
    public int compareTo(edges a) {
        return Integer.compare(cost, a.cost);
    }


    
    
}

public class Main {
    public static void main(String[]args) {
        Scanner input = new Scanner(System.in);
        
        int numHouses = input.nextInt();
        int numRoads = input.nextInt();
        int target = input.nextInt()-1;
        int numQueries = input.nextInt();
        
        ArrayList<edges>[] adjList = new ArrayList[numHouses];
        
        for(int i = 0; i < numHouses; i++) {
            adjList[i] = new ArrayList<edges>();
        }
        
        for(int i = 0; i < numRoads; i++) {
            int from = input.nextInt()-1;
            int to = input.nextInt()-1;
            int cost = input.nextInt();
            
            adjList[from].add(new edges(to,cost));
            adjList[to].add(new edges(from,cost));
        }
        
        boolean[] vis = new boolean[numHouses];
        int [] dis = new int[numHouses];
        Arrays.fill(dis, Integer.MAX_VALUE);
        dis[target] = 0;
        PriorityQueue<edges> q = new PriorityQueue<edges>();
        q.add(new edges(target,0));
        
        while(!q.isEmpty()) {
            edges cur = q.poll();
            int ver = cur.to;
            if(vis[ver]) continue;
            
            vis[ver] = true;
            
            ArrayList<edges> adj = adjList[ver];            
            
            for(int i = 0; i < adj.size(); i++) {
                int v = adj.get(i).to;
                int w = adj.get(i).cost;
                
                if(dis[v] > dis[ver] + w) {
                    dis[v] = dis[ver] + w; 
                    q.add(new edges(v, dis[v]));
                }
                
            }
            
        }
        
        for(int i = 0; i < numQueries; i++) {
            int node = input.nextInt()-1;
            if(dis[node] == Integer.MAX_VALUE) {
                System.out.println(-1);
                continue;
            }
        
                System.out.println(dis[node]);            
            
        }
        
        
        
    }
}