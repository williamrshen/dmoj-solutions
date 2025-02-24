import java.util.*;
public class WorldOfStarCraft {
	public static int[] p;
	public static int findParent (int a) {
		
		if(p[a] != a) {
			p[a] = findParent(p[a]);
		}
		
		return p[a];
	}
	
	
	public static void main(String[]args) {
		Scanner input = new Scanner(System.in);
		int numPlanets = input.nextInt();
		int numConnections = input.nextInt();
		int numQueries = input.nextInt();
		String type = input.next();
		p = new int[numPlanets + 5];
		
		for(int i = 0; i <= numPlanets; i++) {
			p[i] = i;
		}
		
		
		for(int i = 0; i < numConnections; i++) {
			int a = input.nextInt()-1;
			int b = input.nextInt()-1;
			
			if(type.charAt(a) != type.charAt(b)) continue;
			
			p[findParent(a)] = findParent(b);
		}
		int ans = 0;
		for(int i = 0; i < numQueries; i++) {
			int a = input.nextInt()-1;
			int b = input.nextInt()-1;
			
			if(findParent(a) == findParent(b)) ans++;
		}
		System.out.println(ans);
		
		
		
	
	}
}