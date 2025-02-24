import java.util.*;

public class BoardGames {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int start = in.nextInt();
        int end = in.nextInt();

        boolean[] visited = new boolean[10000001];

        Queue<Integer> q = new LinkedList();
        Queue<Integer> moves = new LinkedList();

        q.add(start);
        moves.add(0);
        visited[start] = true;

        if(start == end){
            System.out.println(0);
            q.clear();
        }

        while(!q.isEmpty()){
            int s = q.remove();
            int m = moves.remove();

            if(s < (int)1e6 && !visited[s*3]){
                if(s*3 == end){
                    System.out.println(m+1);
                    break;
                }
                visited[s*3] = true;
                q.add(s*3);
                moves.add(m+1);
            }
            if(s - 3 >= 0 && !visited[s-3]){
                if(s-3 == end){
                    System.out.println(m+1);
                    break;
                }
                visited[s-3] = true;
                q.add(s-3);
                moves.add(m+1);
            }
            if(s - 1 >= 0 && !visited[s-1]){
                if(s-1 == end){
                    System.out.println(m+1);
                    break;
                }
                visited[s-1] = true;
                q.add(s-1);
                moves.add(m+1);
            }
            if(!visited[(int)s/2] && s%2 == 0){
                if(s/2 == end){
                    System.out.println(m+1);
                    break;
                }
                visited[(int)s/2] = true;
                q.add(s/2);
                moves.add(m+1);
            }

        }

    }

}