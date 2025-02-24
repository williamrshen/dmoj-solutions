import java.io.*;
import java.util.*;
public class Main {
    static Node[] nodes;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {

        for (int k = 0; k < 5; k ++) {
            nodes = new Node[101];
            for (int i = 0; i < nodes.length; i++) nodes[i] = new Node();
            int n = readInt();
            for (int i = 0; i < n; i++) {
                int b = readInt(), e = readInt();
                nodes[b].out.add(nodes[e]);
            }
            for (int i = 0; i < nodes.length; i++) {
                for (int j = 0; j < nodes.length; j++) nodes[j].visited = false;

                int ans = solve(nodes[i], nodes[i], 0);
                if (ans != -1) {
                    System.out.println(ans);
                    break;
                }
            }
        }

    }

    static int solve (Node s, Node c, int d) {
        c.visited = true;
        for (Node next : c.out) {
            if (next == s) return d + 1;
            else if (!next.visited) {
                int temp = solve(s, next, d + 1);
                if (temp != -1) return temp;
            }
        }
        c.visited = false;
        return -1;
    }

    static class Node {
        List<Node> out;
        boolean visited;
        public Node() {
            out = new ArrayList<>();
            visited = false;
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
}