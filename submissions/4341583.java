import java.util.*;
import java.io.*;

public class Main {

    static int n, m;
    static char[][] g;
    static boolean[][] visited;

    static class Point{
        int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;

        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int c = Integer.parseInt(br.readLine());
        n = Integer.parseInt(br.readLine());
        m = Integer.parseInt(br.readLine());

        g = new char[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) g[i] = br.readLine().toCharArray();

        ArrayList<Integer> counts = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int o = 0; o < m; o++) {
                if (g[i][o] == '.' && !visited[i][o]) counts.add(bfs_visit(i, o));

            }
        }

        Collections.sort(counts, Collections.reverseOrder());

        int count = 0;
        for (int sizes: counts) {
            if (sizes > c) break;

            count++;
            c -= sizes;
        }
        if (count == 1) System.out.println(count + " room, " + c + " square metre(s) left over");
        else System.out.println(count + " rooms, " + c + " square metre(s) left over");
    }

    public static int bfs_visit(int a, int b){
        Deque<Point> queue = new ArrayDeque();
        queue.add(new Point(a, b));

        int count = 0;

        while (!queue.isEmpty()) {
            Point p = queue.pollFirst();
            int x = p.x;
            int y = p.y;

            if (visited[x][y] || g[x][y] == 'I') continue;
            count++;
            visited[x][y] = true;

            if (x > 0) queue.add(new Point(x - 1, y));
            if (x < n - 1) queue.add(new Point(x + 1, y));
            if (y > 0) queue.add(new Point(x, y - 1));
            if (y < m - 1) queue.add(new Point(x, y + 1));
        }

        return count;
    }
}