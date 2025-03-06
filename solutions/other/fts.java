import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        char[] l = sc.next().toCharArray();
        int count = 0;
        boolean now = false;
        if (l[0] == '1') {
            now = true;
        } else {
            now = false;
        }
        for (int i = 0; i < n; i ++) {
            if (l[i] == '1' && now == false) {
                count ++;
                now = true;
            }
            if (l[i] == '0' && now == true) {
                count ++;
                now = false;
            }
        }
        if (l[n-1] == '1') {
            System.out.println(count + 1);
        } else {
            System.out.println(count);
        }
    }
}