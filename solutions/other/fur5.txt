import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    public static void main(String[] args) throws IOException {
        Hanoi(readInt(), 'A', 'C', 'B');
    }

    static void Hanoi (int n, char A, char B, char C)
    {
        if (n==1)
        {
            System.out.println(String.valueOf(A) + String.valueOf(B));
        }
        else
        {
            Hanoi (n-1, A, C, B);
            System.out.println(String.valueOf(A) + String.valueOf(B));
            Hanoi(n-1, C, B, A);
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
    static char readCharacter () throws IOException {
        return next().charAt(0);
    }
}