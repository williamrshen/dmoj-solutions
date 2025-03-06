import java.util.*;
import java.io.*;

public class Main {
    public static int n;
    public static int[] s;

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int longest = 0;
        n = sc.nextInt();
        s = new int[n];

        for (int i = 0; i < n; i++) {
            s[i] = sc.nextInt();
        }

        for (int i = 0; i < n - 1; i++) {
            if (subsequence(i) > longest) {
                longest = subsequence(i);
            }
        }

        System.out.println(longest);

    }


    public static int subsequence(int start) {
        int longest = 0;
        for (int i = start; i < n - 1; i++) {
            if (Math.abs((s[i] - s[i + 1])) > 2) {
                break;
            }
            longest ++;
        }
        return longest+1;
    }
}