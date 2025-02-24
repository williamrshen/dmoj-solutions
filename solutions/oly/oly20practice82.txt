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
            int left = sc.nextInt();
            int right = sc.nextInt();
            if (left > s[n-1] || right < s[0]) {
                System.out.println(0);
                continue;
            }
            if (left < s[0] && right > s[n-1]) {
                System.out.println(n);
                continue;
            }
            int l = Arrays.binarySearch(s, left);
            if (l < 0) {
                l = -l-1;
            }
            int r = Arrays.binarySearch(s, right);
            if (r < 0) {
                r = -r-2;
            }
            System.out.println(r-l+1);
        }
    }
}