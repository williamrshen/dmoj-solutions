import java.util.*;

public class Solution {
  public static int[] parent;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int V = sc.nextInt();
    int E = sc.nextInt();
    LinkedList<Integer> mst = new LinkedList<Integer>();
    parent = new int[V];    //fill with -1
    Arrays.fill(parent, -1);
    
    for(int i=0; i<E; i++) {
      int bv = sc.nextInt()-1;
      int ev = sc.nextInt()-1;
      int pb = find(bv);
      int pe = find(ev);
      if(pe!=pb) {
        union(pb, pe);
        mst.add(i+1);
        if (mst.size()==V-1) {
           break;
        }
      } 
    }
  
    if (mst.size()==V-1) {
      for (int i:mst) {
        System.out.println(i);
      }
    } else {
      System.out.println("Disconnected Graph");
    }
  
  }  
                            
  public static int find(int v) {
    if(parent[v]==-1) {
      return v;
    }
    else {
      parent[v] = find(parent[v]);
      return parent[v];
    }
  }

  public static void union(int x, int y){
    parent[x] = y;
  }
 
}