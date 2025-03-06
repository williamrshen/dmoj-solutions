import java.util.*;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        String a = sc.next();
        char[] aa = a.toCharArray();
        for (int i = 0; i < n; i ++) {
            if (aa[i] == 'o') {
                m ++;
            } else {
                if (m != 0) {
                    m --;
                }
            }
        }
        System.out.print(m);
    }
}