import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int t = sc.nextInt();

        int x = Math.abs(a - c);
        int y = Math.abs(b - d);

        if (t < x + y) {
            System.out.println("N");
            return;
        }

        if ((x + y) % 2 == t % 2) {
            System.out.println("Y");
        } else {
            System.out.println("N");
        }
    }
}