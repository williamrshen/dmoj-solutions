import java.util.Arrays;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; i ++) {
            s[i] = sc.nextInt();
        }
        Arrays.sort(s);
        for (int i = 0; i < q; i ++) {
            int L = sc.nextInt();
            int R = sc.nextInt();
            int l = Arrays.binarySearch(s, L);
            if (l < 0) {
                l = -l-1;
            }
            int r = Arrays.binarySearch(s, R);
            if (r < 0) {
                r = -r-2;
            }
            System.out.println(r-l + 1);
        }
    }
}