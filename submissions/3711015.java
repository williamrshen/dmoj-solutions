import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    public static void main(String[] args) throws IOException{
        Scanner sc = new Scanner(System.in);
        LinkedList<Integer> temp = new LinkedList<>();
        LinkedList<String> city = new LinkedList<>();
        while (true) {
            String c = sc.next();
            int t = sc.nextInt();
            if (c.equals("Waterloo")) {
                temp.add(t);
                city.add(c);
                break;
            }
            temp.add(t);
            city.add(c);
        }
        int a = Integer.MAX_VALUE;
        String b = "";
        for (int i = 0; i < temp.size(); i ++) {
            if (temp.get(i) < a) {
                a = temp.get(i);
                b = city.get(i);
            }
        }
        System.out.println(b);
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