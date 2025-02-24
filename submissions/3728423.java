import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        int count = 0;

        for (int i = 1; i < n; i ++) {
            if (s[i] != s[i-1]) {
                count ++;
            }
        }
        if (s[n-1] == '1') count ++;
        System.out.println(count);

    }
}