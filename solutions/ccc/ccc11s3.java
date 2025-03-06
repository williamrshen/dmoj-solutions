import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        int t = readInt();
        for (int i = 0; i < t; i ++) {
            int m = readInt();
            int x = readInt();
            int y = readInt();
            int topY = topY(m, x);
            if (y >= topY) System.out.println("empty");
            else System.out.println("crystal");
        }
    }


    public static int topY(int m, int x) {
        if (m == 0) return 0;
        int zonesize = (int)Math.pow(5,m-1);
        int zone = x/zonesize;
        if(zone == 1 || zone == 3) return zonesize + topY(m-1, x%zonesize);
        else if(zone == 2) return 2*zonesize + topY(m-1, x%zonesize);
        else return 0;

    }

    static String next () throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static int readInt () throws IOException {
        return Integer.parseInt(next());
    }
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}