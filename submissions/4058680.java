import java.util.*;
import java.io.*;
public class definitions {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int length = readInt();
        ArrayList<String> ray = new ArrayList<>();
        for (int i = 0; i < length; i++){
            ray.add(next());
        }
        ray.sort(new sort());
        Collections.reverse(ray);
        for (String i : ray){
            System.out.print(i);
        }
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
class sort implements Comparator<String> {
    public int compare(String a, String b) {
        // return a.compareTo(b);
        return (a+b).compareTo(b+a);
    }
}