import java.util.*;
import java.io.*;
public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException{
        int m = readInt(), n = readInt(), k = readInt();
        long ans = 0;
        Long[] h = new Long[k];
        for(int i = 0; i < k; i ++) {
            h[i] = readLong();
        }
        Arrays.sort(h, Collections.reverseOrder());
        
        int cols = Math.min((int) Math.ceil((double)k / (double)m), n);
        for(int i = 0; i <= k; i ++) {
            for(int j = 1; j < m; j ++) {
                if (cols >= k) break;
                    ans += h[i] - h[cols] + j;
                    cols ++;
            }
        }
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
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
    static String readLine () throws IOException {
        return br.readLine().trim();
    }
}