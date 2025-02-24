import java.util.*;

public class Main {

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

        if (start == end) {
            System.out.println(0);
            q.clear();
        }

        while (!q.isEmpty()) {
            int s = q.remove();
            int m = moves.remove();

            visited[s] = true;
            if (3 * s < (int) 1e6) {
                if (!visited[s * 3]) {
                    visited[s * 3] = true;
                    q.add(s * 3);
                    moves.add(m + 1);
                }
            }
            if (s - 3 > 0) {
                if (!visited[s - 3]) {
                    q.add(s - 3);
                    moves.add(m + 1);
                    visited[s - 3] = true;
                }
            }
            if (s - 1 > 0) {
                if (!visited[s - 1]) {
                    q.add(s - 1);
                    moves.add(m + 1);
                    visited[s - 1] = true;
                }
            }
            if (s % 2 == 0) {
                if (!visited[s / 2]) {
                    q.add(s / 2);
                    moves.add(m + 1);
                    visited[s / 2] = true;
                }
            }
            if (visited[end]) { System.out.println(m + 1); return; }
        }


    }

}